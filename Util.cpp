// Функция для определения длины строки
int  length(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}
// Функция для копирования строки
void copy(const char* source, char* destination, int len) {
    for (int i = 0; i < len; ++i) {
        destination[i] = source[i];
    }
    destination[len] = '\0'; // Добавляем завершающий нулевой символ
}