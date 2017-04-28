##Transfer large file between linux servers:
 * Foreign server to in-house server:
	 * via `ssh` + `pv` (first choice):

			############################################
			## push (from in-house server's perspective)
			############################################
			root# apt-get install -y pv
			root# tar zcv $file_name | pv \ 
			| ssh $user@$dst_ip 'tar zxv -C $dst_dir'
			
			# performance: 
			#    126MiB 0:17:37, from HK to Harbin.
			#    avg: 122KiB/s
			
			############################################
			## pull, of same speed as push, and safer.
			############################################
			root# ssh $remote_user@src_ip 'tar zcvf -  -C $src_dir $file_name' \
			| pv | tar zxv -C $dst_dir
			
			# performance: 
			#    204MiB 0:31:41, from Shenzhen to Harbin.
			#    avg: KiB/s
	 * via `rsync`:

			root# 

	 * via `nfs`:  
	 more suitable for constant random access
	 * via `nc`:  
	 no recommended:  
	 no significant speed boost, plus no safety at all.