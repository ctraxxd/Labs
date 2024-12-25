#include <iostream>

int readInt() {
    int c = getchar();
    while (c == ' ' || c == '\n')
        c = getchar();
    int sign = 1;
    long long x = 0;
    if (c == '-')
        sign = -1, c = getchar();
    bool b = false;
    while (c != '\n') {
        if (c < '0' || c > '9') {
            if (c == ' ') {
                b = true;
                c = getchar();
                continue;
            } else {
                x = -2147483648;
                sign = 1;
                break;
            }
        }
        if (b) {
            x = -2147483648;
            sign = 1;
            break;
        }
        x = (x << 3) + (x << 1) + (c - '0');
        if (x > 2147483647) {
            x = -2147483648;
            sign = 1;
            break;
        }
        c = getchar();
    }
    while (c != '\n')
        c = getchar();
    return x * sign;
}

void Task() {
    std::cout << "Первый раб выпил вино из бочек с номерами: ";
    int cnt = 0;
    for (int i = 1; i <= 240; i++) {
        if ((i / 1) % 3 == 1) {
            if (cnt)
                std::cout << ", " << i;
            else std::cout << i;
            cnt++;
        }
    }
    std::cout << '\n';
    std::cout << "Второй раб выпил вино из бочек с номерами: ";
    cnt = 0;
    for (int i = 1; i <= 240; i++) {
        if ((i / 3) % 3 == 1) {
            if (cnt)
                std::cout << ", " << i;
            else std::cout << i;
            cnt++;
        }
    }
    std::cout << '\n';
    std::cout << "Третий раб выпил вино из бочек с номерами: ";
    cnt = 0;
    for (int i = 1; i <= 240; i++) {
        if ((i / 9) % 3 == 1) {
            if (cnt)
                std::cout << ", " << i;
            else std::cout << i;
            cnt++;
        }
    }
    std::cout << '\n';
    std::cout << "Четвертый раб выпил вино из бочек с номерами: ";
    cnt = 0;
    for (int i = 1; i <= 240; i++) {
        if ((i / 27) % 3 == 1) {
            if (cnt)
                std::cout << ", " << i;
            else std::cout << i;
            cnt++;
        }
    }
    std::cout << '\n';
    std::cout << "Пятый раб выпил вино из бочек с номерами: ";
    cnt = 0;
    for (int i = 1; i <= 240; i++) {
        if ((i / 81) % 3 == 1) {
            if (cnt)
                std::cout << ", " << i;
            else std::cout << i;
            cnt++;
        }
    }
    std::cout << '\n';
    int ans[] = {0, 0, 0, 0, 0};
    int t;
    while (true) {
        std::cout << "Введите 0, если первый раб умер или 1, если выжил: ";
        t = readInt();
        if (t == 0 || t == 1)
            break;
        std::cout << "Неправильный формат ввода. ";
    }
    if (t == 0)
        ans[0] = 1;
    while (true) {
        std::cout << "Введите 0, если второй раб умер или 1, если выжил: ";
        t = readInt();
        if (t == 0 || t == 1)
            break;
        std::cout << "Неправильный формат ввода. ";
    }
    if (t == 0)
        ans[1] = 1;
    while (true) {
        std::cout << "Введите 0, если третий раб умер или 1, если выжил: ";
        t = readInt();
        if (t == 0 || t == 1)
            break;
        std::cout << "Неправильный формат ввода. ";
    }
    if (t == 0)
        ans[2] = 1;
    while (true) {
        std::cout << "Введите 0, если четвертый раб умер или 1, если выжил: ";
        t = readInt();
        if (t == 0 || t == 1)
            break;
        std::cout << "Неправильный формат ввода. ";
    }
    if (t == 0)
        ans[3] = 1;
    while (true) {
        std::cout << "Введите 0, если пятый раб умер или 1, если выжил: ";
        t = readInt();
        if (t == 0 || t == 1)
            break;
        std::cout << "Неправильный формат ввода. ";
    }
    if (t == 0)
        ans[4] = 1;
    if (!ans[0]) {
        std::cout << "Первый раб выпил вино из бочек с номерами: ";
        cnt = 0;
        for (int i = 1; i <= 240; i++) {
            if ((i / 1) % 3 == 2) {
                if (cnt)
                    std::cout << ", " << i;
                else std::cout << i;
                cnt++;
            }
        }
        std::cout << '\n';
    }
    if (!ans[1]) {
        std::cout << "Второй раб выпил вино из бочек с номерами: ";
        cnt = 0;
        for (int i = 1; i <= 240; i++) {
            if ((i / 3) % 3 == 2) {
                if (cnt)
                    std::cout << ", " << i;
                else std::cout << i;
                cnt++;
            }
            std::cout << '\n';
        }
    }
    if (!ans[2]) {
        std::cout << "Третий раб выпил вино из бочек с номерами: ";
        cnt = 0;
        for (int i = 1; i <= 240; i++) {
            if ((i / 9) % 3 == 2) {
                if (cnt)
                    std::cout << ", " << i;
                else std::cout << i;
                cnt++;
            }
        }
        std::cout << '\n';
    }
    if (!ans[3]) {
        std::cout << "Четвертый раб выпил вино из бочек с номерами: ";
        cnt = 0;
        for (int i = 1; i <= 240; i++) {
            if ((i / 27) % 3 == 2) {
                if (cnt)
                    std::cout << ", " << i;
                else std::cout << i;
                cnt++;
            }
        }
        std::cout << '\n';
    }
    if (!ans[4]) {
        std::cout << "Пятый раб выпил вино из бочек с номерами: ";
        cnt = 0;
        for (int i = 1; i <= 240; i++) {
            if ((i / 81) % 3 == 2) {
                if (cnt)
                    std::cout << ", " << i;
                else std::cout << i;
                cnt++;
            }
        }
        std::cout << '\n';
    }
    if (!ans[0]) {
        while (true) {
            std::cout << "Введите 0, если первый раб умер или 1, если выжил: ";
            t = readInt();
            if (t == 0 || t == 1)
                break;
            std::cout << "Неправильный формат ввода. ";
        }
        if (t == 0)
            ans[0] = 2;
    }
    if (!ans[1]) {
        while (true) {
            std::cout << "Введите 0, если второй раб умер или 1, если выжил: ";
            t = readInt();
            if (t == 0 || t == 1)
                break;
            std::cout << "Неправильный формат ввода. ";
        }
        if (t == 0)
            ans[1] = 2;
    }
    if (!ans[2]) {
        while (true) {
            std::cout << "Введите 0, если третий раб умер или 1, если выжил: ";
            t = readInt();
            if (t == 0 || t == 1)
                break;
            std::cout << "Неправильный формат ввода. ";
        }
        if (t == 0)
            ans[2] = 2;
    }
    if (!ans[3]) {
        while (true) {
            std::cout << "Введите 0, если четвертый раб умер или 1, если выжил: ";
            t = readInt();
            if (t == 0 || t == 1)
                break;
            std::cout << "Неправильный формат ввода. ";
        }
        if (t == 0)
            ans[3] = 2;
    }
    if (!ans[4]) {
        while (true) {
            std::cout << "Введите 0, если пятый раб умер или 1, если выжил: ";
            t = readInt();
            if (t == 0 || t == 1)
                break;
            std::cout << "Неправильный формат ввода. ";
        }
        if (t == 0)
            ans[4] = 2;
    }
    std::cout << "Номер отравленной бочки: " << ans[4] * 81 + ans[3] * 27 + ans[2] * 9 + ans[1] * 3 + ans[0] << "\n\n";
}