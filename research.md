#topology project:
---
##docker env setup:
 * Dockerfile usage:
	 * The main purpose of a `CMD` is to provide defaults for an executing container. [[1]](https://docs.docker.com/engine/reference/builder/#/cmd)
	 * `ENTRYPOINT` by default is `/bin/sh -c`,
	 * In a nutshell, `ENTRYPOINT` does not get overwritten by `docker run`, `CMD` does.
	 * Purpose to use a Dockerfile: **to automate** Docker image creation.
	 * `VOLUME` is not used for volume binding, because that will damage portability. `VOLUME` actually tells the directory to not go into image.
 * Dockerfile:

		FROM ubuntu:latest
		
		MAINTAINER johnsonyue version: 0.01
		
		#replace default apt source & install necessary packages.
		RUN sed -i 's/archive.ubuntu.com/mirrors.tuna.tsinghua.edu.cn/g' /etc/apt/sources.list
		RUN apt-get update && apt-get install -y vim git tar python python-setuptools
		
		#setup code env.
		##source.
		ENV THESIS_ENV=/home/thesis_env/
		RUN mkdir -p /home/thesis_env
		WORKDIR $THESIS_ENV
		RUN git clone http://github.com/johnsonyue/thesis_analyzer
		VOLUME $THESIS_ENV/temp/
		COPY thesis_env.tar.gz.* $THESIS_ENV/temp/
		WORKDIR $THESIS_ENV/thesis_analyzer/analyzer/
		RUN cat $THESIS_ENV/temp/thesis_env.tar.gz.* | tar zxvf -
		##IP2Location.
		WORKDIR IP2Location-Python-master/
		RUN python setup.py install
		WORKDIR ../
		##Maxmind
		WORKDIR GeoIP2-python-master/
		RUN python setup.py install
		WORKDIR ../
		
		#use default entrypoint: /bin/sh -c
		CMD ["/bin/bash"]

##sql scheme:
 * tbls:

		create database xxx;
		use xxx;
		
		create table traces (
		
			//header fields.
			id bigint not null auto increment primary key,
			src_ip char(4) not null,
			dst_ip char(4) not null,
			timestamp timestamp not null,
			source varchar(10),
			date date,
			monitor varchar(50),
			
			//reply fields.
			dest_replied boolean,
			dest_rtt int,
			request_ttl int,
			replied_ttl int,
			
			//halt fields.
			//Success, Unreachable, Loop detected, Gap detected.
			halt_reason enum('S','U','L','G'),
			halt_data int,
			//HaltReason            HaltReasonData
			//S (success/no_halt)    0
			//U (icmp_unreachable)   icmp_code
			//L (loop_detected)      loop_length
			//G (gap_detected)       gap_limit
			
			//path fields.
			path_complete boolean,
			path text
			
			
		);
		
		create table node_caida_20160712 (
			id int not null auto increment primary key,
			ip char(4) not null,
			geoloc text //json dict.
		};
		
		create table edges_caida_20160712 (
			src int,
			dst int,
			foreign key(src) references node_caida_20160712(id),
			foreign key(dst) references node_caida_20160712(id)
		);
		
## programming:
 * bash uses `[]` as `test` cmd, `[[]]`` as a keyword, 