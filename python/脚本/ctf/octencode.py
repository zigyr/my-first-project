def Octencode(str):
    return ''.join([oct(ord(c)).replace('0o', '\\') for c in str])

def main():
    ans = Octencode('select')
    print(ans)


if __name__ == "__main__":
    main()