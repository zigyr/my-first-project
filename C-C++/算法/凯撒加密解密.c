/*
注意像 plaintext.txt、encrypted.txt、decrypted.txt这类文件

在我的vscode环境中，放入output文件夹中，方能被读取到
*/

#include <stdio.h>   // 输入输出、文件读写
#include <ctype.h>   // 字符判断、字母检测
int shift_char(int ch, int key, int encrypt) {
    if (ch >= 'A' && ch <= 'Z') {
        int base = 'A';
        int offset = ch - base;
        if (encrypt)
            return (offset + key) % 26 + base;
        return (offset - key + 26) % 26 + base;
    }
    if (ch >= 'a' && ch <= 'z') {
        int base = 'a';
        int offset = ch - base;
        if (encrypt)
            return (offset + key) % 26 + base;
        return (offset - key + 26) % 26 + base;
    }
    return ch;
}
void process_file(const char *infile, const char *outfile, int key, int encrypt) {
    FILE *fin = fopen(infile, "r");
    FILE *fout = fopen(outfile, "w");
    int ch;
    if (!fin || !fout) {
        printf("file open error\n");
        if (!fin) printf("输入文件打开失败: %s\n", infile);
        if (!fout) printf("输出文件打开失败: %s\n", outfile);
        return;
        return;
    }
    while ((ch = fgetc(fin)) != EOF) {
        fputc(shift_char(ch, key, encrypt), fout);
    }
    fclose(fin);
    fclose(fout);
}
int main () {
    int key = 4;
    // process_file("plaintext.txt", "encrypted.txt", key, 1);
    process_file("encrypted.txt", "decrypted.txt", key, 0);
    printf("done\n");
    return 0;
}