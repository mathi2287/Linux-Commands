**Linux Commands**

**1. grep – global regular expression print**
    • Search for a perticular string/keyword in a file and print lines matching a pattern.
    •  It checks line by line and prints lines matching the pattern.
    • We can use grep anywhere like with files, searching for file, directories, etc.
    • Syntax – grep [opt]... pattern [file_name]...
    • We also combines ‘|’  grep command with other commands.
      Example: ls | grep file2   -- shows files whoose name was file2.
    • To ignore the upper and lower case while searching
        ◦ grep Candy users.csv      --grep “keyword” “file_name”
    • Case 1: Ignore the case sensitive while searching ( -i )
        ◦ grep -i “pattern” file_name
    • Case 2: To search everything (lines) except give pattern/keyword ( -v )
        ◦ grep -v “pattern” file_name
    • Case 3: To print counts of given keyword present in a file ( -c )
        ◦ grep -c “keyword” file_name
    • Case 4: Print the line number of matches of given keyword ( -n )
        ◦ grep -n “keyword” file_name
    • Case 5: To print the exact keyword match lines ( -w )
        ◦ grep -w “leyword” file_name (if keyword is “tech”, it shows only tech rather than words like technology, technician, technical, etc..)
    • Case 6: To search a given keyword in multiple files
        ◦ grep keyword file1_name file2_name file3_name (It shows file_name with keyword)
    • Case 7: To suppres file names while search a given keyword with multiple files ( -h )
        ◦ grep -h keyword file1 file2 file2 (It shows only matching word without file names)
    • Case 8: To search multiple keywords in a file ( -e or | )
        ◦ grep -e keyword1 -e keyword2 file_name or
        ◦ egrep “keyword1|keyword2|keyword3” file_name
    • Case 9: To only print the file_names which matches given keywords ( -l )
        ◦ grep -l keyword file1 file2 file2
    • Case 10: Get the keyword pattern from one file and match with another file ( -f )
        ◦ grep -f file1_which_has_pattern file2_where_to_be_find ( -f points to file1, takes this pattern/keywords as reference and search with file2)
    • Case 11: Print the matching line which start with given keyword ( ^ )
        ◦ grep ^pattern file_name ( prints lines which start with given pattern) it also applicable for multiple files.
    • Case 12: Print the matching line which end with given keyword ( $ )
        ◦ grep keyword$ file_name
    • Case 13: Search a keyword in all files in the directory ( -R ) R means recursive mode
        ◦ grep -R keyword dirA/
    • Case 14: If just want to search but don’t want to print on terminal
        ◦ grep -q “keyword” file_name
        ◦ after executing the above command we can check whether this command status by using echo $? - echo $? used to check whether the previous command executed successfully or not.
    • Case 15: Print file names that match with keyword
        ◦ ls | grep -i keyword.
