def count_substring(string, sub_string):
    count = 0
    len_substr = len(sub_string)
    for i in range(0,len(string)-len(sub_string)+1):
        #print(string[i:len_substr])
        if(string[i:len_substr] == sub_string): 
            count+=1
        len_substr+=1
    return count