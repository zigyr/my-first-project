def my_submd5(s):
    import hashlib
    for i in range(100000):
        x = str(i).encode()
        y = hashlib.md5(x)
        m = y.hexdigest()
        if m[-6:] == s:
            print(i)
            print("爆破结果为" + m)
            break

def main():
    my_submd5("8b184b")


if __name__ == "__main__":
    main()