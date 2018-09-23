/*************************************************************************
	> File Name: 9.22.c
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2018年09月22日 星期六 22时08分26秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>
#include <math.h>

int dig(long long int n) {
    return floor(log10(n)) + 1;
}

int my_printf(const char *frm, ...) {
    int cnt = 0;
    va_list arg;
    va_start(arg, frm);
    for (int i = 0; frm[i]; i++) {
        switch (frm[i]) {
            case '%' : {
                i++;
                switch(frm[i]) {
                    case 'd' : {
                        long long temp = va_arg(arg, int);
                        if (temp < 0) {
                            putchar('-');
                            cnt++;
                            temp = -temp;
                        }
                        int dig_temp = dig(temp);

                        while (temp) {
                            int x = temp / (int)pow(10, dig_temp -1);
                            putchar(x + '0');
                            cnt++;
                            temp = temp % (int)pow(10, dig_temp -1);
                            dig_temp -= 1;
                        }
                        for (int i = 0; i < dig_temp; i++){
                            putchar('0');
                            cnt++;
                        }
                        break;
                    }
                    default : 
                        fprintf(stderr, "error : unknow %%%c\n", frm[i]); 
                        exit(1);
                }
            } break;
            default:
            putchar(frm[i]);
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n = 123;
    my_printf("hello world\n");
    my_printf("n = %d\n", n);
    my_printf("n = %d\n", 12000);
    my_printf("n = %d\n", -567);
    my_printf("n = %d\n", INT32_MIN);
    my_printf("n = %d\n", INT32_MAX);
    return 0;
}
