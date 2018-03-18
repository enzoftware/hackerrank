def swap_case(s):
    r = ""
    for i in s:
        i = i.upper() if ord(i) > 96 else i.lower()
        r += i
    return r