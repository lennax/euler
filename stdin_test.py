#!/usr/bin/python
# Author: Lenna X. Peterson (github.com/lennax)
# Communicate to spawned process

import subprocess

# First arg: string command or list of command and args
# Second arg: string to pass as stdin
# return value: output of command
def call(CALL, CALL_STDIN): 
	autobuild = subprocess.Popen(CALL, stdin=subprocess.PIPE, stdout=subprocess.PIPE)
	out = autobuild.communicate(CALL_STDIN)[0]
	return out

## Example ##
# Automatically clean and build
call_list = ["./autobuild.py", "7"]
#call(call_list, "1")

# passes "run" to gdb stdin
# puts gdb stdout in gdb_out
gdb_out = call(["gdb", "./build/bin/p2"], "run")
print gdb_out
