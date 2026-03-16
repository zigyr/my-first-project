def my_urlencode(s):
    return ''.join(f'%{ord(c):02X}' for c in s)

def double_urlencode(s):
    return my_urlencode(my_urlencode(s))

def main():
    ans = my_urlencode('e')
    # ans = double_urlencode('admin')
    print(ans)

if __name__ == '__main__':
    main()