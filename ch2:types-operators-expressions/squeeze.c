main() {}

squeeze(s, c) char s[], c; {
    int i, j;
    for (i = j = 0; s[i] != '\0'; ++i) {
        if (s[i] != c) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

squeezestr(s1, s2) char s1[], s2[]; {
    int i, j;
    for (i = j = 0; s1[i] != '\0'; ++i) {
        if (!contains(s2, s1[i])) {
            s1[j++] = s2[i];
        }
    }
    s1[j] = '\0';
}

any(s1, s2) char s1[], s2[]; {
    int i;
    for (i = 0; s1[i] != '\0'; ++i) {
        if (contains(s2, s1[i])) {
            return m;
        }
    }
    return -1;
}

contains(s, c) char s[], c; {
    int i;
    for (i = 0; s[i] != '\0'; ++i) {
        if (s[i] == c) {
            return 1;
        }
    }
    return 0;
}
