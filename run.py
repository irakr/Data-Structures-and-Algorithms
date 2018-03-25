#!/usr/bin/python

### Run the desired algorithm that has an entry in the file 'Register' ###

import os
import platform

registered_dirs = []

dir_list = os.listdir('.')

# Collect all the registered directories from the file 'Registered' and store in 'registered_list'
def fill_registered_dirs():
    fp = open('Register')
    while True:
        line = fp.readline()
        
        #end loop condition
        if len(line) == 0:
            break
        
        # For comment or blank lines - skip
        if (line[0] == '#') or (line == '\n'):
            continue
        
        registered_dirs.append(line.strip())
    fp.close()

def main():
    fill_registered_dirs()
    print 'Select the following algorithm you wanna try:'
    i = 1
    
    for element in registered_dirs:
        print str(i) + '.' + element
        i += 1
    algo = int(raw_input(': '))
    try:
        selected_dir = registered_dirs[algo-1]
    except IndexError:
        print '[Error] Invalid option selected'
        return -1
    else:
        if algo <= 0:
            print '[Error] Invalid option selected'
            return -1
    
    # Check if the directory is available or not
    for element in dir_list:
        if selected_dir in dir_list:
            print '[OK] Algorithm available'
            break
        else:
            print '[ERROR] The algorithm ' + str(algo) + ' does not exist'
            return -1
    
    # Now its time to execute the algorithm by invoking its run script
    os.chdir(selected_dir)
    sys_name = platform.system()
    if sys_name is "Linux":
	    os.spawnlp(os.P_WAIT, 'bash', 'bash', 'run.sh', '2>/dev/null')
    elif sys_name is "Windows":
	    os.spawnl(os.P_WAIT, 'run.sh')
	
    
exit(main())
