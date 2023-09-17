/*
    ให้ผู้ใช้กรอกค่าเข้ามาเก็บในอาเรย์ จากนั้นให้ทำการแสดงค่าข้อมูล 2 แบบคือ "เรียงข้อมูลจากมากไปน้อย" และ "เรียงข้อมูลจากน้อยไปมาก"
    
    Test case:
        Input : 
            1
        Input : 
            5
        Input : 
            1
        Input : 
            4
        Input : 
            6
        Input : 
            9
        Input : 
            13
        Input : 
            -1
    Output:
        0-99 : 1 1 4 5 6 9 13
        99-0 : 13 9 6 5 4 1 1

*/#include <stdio.h>

int main() {
    int data[100];
    int input;
    int size = 0;

    // รับข้อมูลจากผู้ใช้
    while (1) {
        printf("Input: ");
        scanf("%d", &input);
        if (input == -1) {
            break;
        }
        data[size++] = input;
    }

    // เรียงข้อมูลจากน้อยไปมาก (จากต่ำสุดไปยังสูงสุด)
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    // แสดงผลลัพธ์เรียงข้อมูลจากน้อยไปมาก
    printf("0-99 : ");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // เรียงข้อมูลจากมากไปน้อย (จากสูงสุดไปยังต่ำสุด)
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j] < data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    // แสดงผลลัพธ์เรียงข้อมูลจากมากไปน้อย
    printf("99-0 : ");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}
