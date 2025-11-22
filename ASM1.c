#include <stdio.h>
#include <math.h>  // dùng cho hàm sqrt()

// Bảng MENU
void menu() {
    printf("==========================================\n");
    printf("       BẢNG HIỂN THỊ MENU CHỨC NĂNG    \n");
    printf("==========================================\n");
    printf("1. Chức năng tìm tính nguyên của một số\n");
    printf("2. Chức năng tìm UCLN và BCNN\n");
    printf("3. Chức năng tính tiền quán Karaoke\n");
    printf("4. Chức năng tính tiền điện\n");
    printf("6. Chức năng vay tiền ngân hàng\n");
    printf("8. Coming soon...\n");
    printf("0. Thoat chuong trinh\n");
    printf("------------------------------------------\n");
    printf("ban hay chon chuc nang (0-8): ");
}

int main() {
    int luachon;

    do {
        menu();
        scanf("%d", &luachon);

        switch (luachon) {

            // CHỨC NĂNG 1: KIỂM TRA SỐ NGUYÊN TỐ 
            case 1: {
                printf("Bạn chọn CN1\n");

                float x;
                printf("Mời bạn nhập số x: ");
                scanf("%f", &x);

                if (x == (int)x) { // Kiểm tra số nguyên
                    int n = (int)x;
                    printf("%d là số nguyên\n", n);

                    // Kiểm tra số chính phương
                    int sq = (int)sqrt(n);
                    if (sq * sq == n) {
                        printf("%d là số chính phương\n", n);
                    }

                    // Kiểm tra số nguyên tố
                    int isPrime = 1;
                    if (n <= 1) isPrime = 0;
                    else {
                        for (int i = 2; i <= sqrt(n); i++) {
                            if (n % i == 0) {
                                isPrime = 0;
                                break;
                            }
                        }
                    }

                    if (isPrime) printf("%d là số nguyên tố\n", n);
                    else printf("%d KHÔNG phải số nguyên tố\n", n);

                } else {
                    printf("%.2f là số thực\n", x);
                }
                break;
            }

            // CHỨC NĂNG 2: UCLN & BCNN
            case 2: {
                int a, b;
                printf("Nhập a: ");
                scanf("%d", &a);
                printf("Nhập b: ");
                scanf("%d", &b);

                int x = a, y = b;

                while (x != y) {
                    if (x > y) x -= y;
                    else y -= x;
                }
                int ucln = x;
                int bcnn = (a * b) / ucln;

                printf("UCLN = %d\n", ucln);
                printf("BCNN = %d\n", bcnn);
                break;
            }

            // CHỨC NĂNG 3: TÍNH TIỀN KARAOKE
            case 3: {
                int bd, kt;
                printf("Giờ bắt đầu (0-24): ");
                scanf("%d", &bd);
                printf("Giờ kết thúc (0-24): ");
                scanf("%d", &kt);

                if (bd < 0 || bd > 24 || kt < 0 || kt > 24) {
                    printf("Giờ nhập không hợp lệ! Giờ phải nằm trong khoảng 0 - 24.\n");
                    break;
                }

                if (kt <= bd) {
                    printf("Giờ kết thúc phải lớn hơn giờ bắt đầu!\n");
                    break;
                }

                int sogio = kt - bd;
                float tien = 0;
                if (sogio <= 3)
                    tien = sogio * 175000;
                else
                    tien = 3 * 175000 + (sogio - 3) * 155000;

                printf("Tiền Karaoke = %.0f VND\n", tien);
                break;
            }

            // CHỨC NĂNG 4: TÍNH TIỀN ĐIỆN
            case 4: {
                int kw;
                printf("Nhập số KW tiêu thụ: ");
                scanf("%d", &kw);

                float tien = 0;
                if (kw <= 50)
                    tien = kw * 2000;
                else if (kw <= 100)
                    tien = 50 * 2000 + (kw - 50) * 2150;
                else
                    tien = 50 * 2000 + 50 * 2150 + (kw - 100) * 2050
                    ;

                printf("Tiền điện = %.0f VND\n", tien);
                break;
            }
            // DỪNG CHƯƠNG TRÌNH ĐỂ CHỜ NGƯỜI DÙNG
               char c;
                printf("\nNhấn phím bất kỳ để quay lại menu...");
                scanf(" %c", &c);
            // CHỨC NĂNG 6: VAY TIỀN NGÂN HÀNG
            case 6: {
                float goc, lai;
                int thang;
                printf("Nhập số tiền vay: ");
                scanf("%f", &goc);
                printf("Nhập lãi suất (%%/tháng): ");
                scanf("%f", &lai);
                printf("Nhập số tháng vay: ");
                scanf("%d", &thang);

                if (goc <= 0 || lai < 0 || thang <= 0) {
                    printf("Dữ liệu không hợp lệ! Vui lòng nhập lại.\n");
                    break;
                }

                float tienLai = goc * (lai / 100) * thang;
                float tongTien = goc + tienLai;

                printf("Tiền lãi phải trả = %.0f VND\n", tienLai);
                printf("Tổng tiền phải trả = %.0f VND\n", tongTien);
                break;
            }

            // CHỨC NĂNG 8: COMING SOON
            case 8:
                printf("Chức năng đang phát triển...\n");
                break;

            // CHỨC NĂNG 0: THOÁT
            case 0:
                printf("Thoát chương trình!\n");
                break;

            default:
                printf("Lựa chọn không hợp lệ. Vui lòng chọn lại!\n");
        }

    } while (luachon != 0);

    return 0;
}
