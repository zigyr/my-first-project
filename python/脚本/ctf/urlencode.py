def my_urlencode(s):
    return ''.join(f'%{ord(c):02X}' for c in s)

print(my_urlencode(my_urlencode('admin')))