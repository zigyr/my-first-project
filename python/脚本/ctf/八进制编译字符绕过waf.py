def encodeOctal(str):
    code = ''.join([oct(ord(c)).replace('0o', '\\') for c in str])
    print(code)

def main():
    str = input("输入:")
    encodeOctal(str)


if __name__ == "__main__":
    main()