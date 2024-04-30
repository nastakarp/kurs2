// Функция для определения длины строки
int length(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Функция для копирования строки
void copy(const char *source, char *destination, int len) {
    for (int i = 0; i < len; ++i) {
        destination[i] = source[i];
    }
    destination[len] = '\0'; // Добавляем завершающий нулевой символ
}

int extractYear(const char *dateStr) {
    int year = 0;
    // Ищем позицию первого символа '-'
    int pos = 0;
    while (dateStr[pos] != '-' && dateStr[pos] != '\0') {
        pos++;
    }
    // Переводим символы до первого '-' в число
    for (int i = 0; i < pos; ++i) {
        if (dateStr[i] >= '0' && dateStr[i] <= '9') {
            year = year * 10 + (dateStr[i] - '0');
        }
    }
    return year;
}
int strcmp(const char *str1, const char *str2) {
    while (*str1 && *str2 && *str1 == *str2) {
        ++str1;
        ++str2;
    }
    return *str1 - *str2;
}
