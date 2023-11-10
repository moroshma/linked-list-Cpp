//
// Created by moroshma on 10.11.23.
//

#include "Slist.h"
template <typename T>
void handlerStr( List<T> * str, FILE * stream) {

    int fl = 0;
    for (int i = 0; i < str->getSize() - 1; i++) {

        if (i == 0 && str->nodeByIndex(i)->data == 'a') {
            fl = 1;
        } else if (!fl && str->nodeByIndex(i)->data == 'a' && str->nodeByIndex(i - 1) -> data == ' ') {
            fl = 1;
        } else if (!fl && str->nodeByIndex(i)->data != ' ') {
            fputc(str->nodeByIndex(i) -> data, stream);
        }
        if (str->nodeByIndex(i)->data == ' ') {
            fputc(str->nodeByIndex(i) -> data, stream);
            fl = 0;
        }
    }

}

template <typename T>
void Input(List<T> & str, FILE * stream) {
    int c = fgetc(stream);
    while (c != '\n' && c != EOF) {
        str.push_back(c);
        c = fgetc(stream);
    }
    str.push_back('\0');
}
int main() {

    List<char> list;
    FILE * fs = fopen("test.txt", "r");
    Input(list, fs);
    fclose(fs);
    list.print_list();



    FILE* fs2 = fopen("test.txt", "w");

    handlerStr(&list, fs2);


    fclose(fs2);





    return SUCCESS;
}