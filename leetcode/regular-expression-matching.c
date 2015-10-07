bool isMatch(char* s, char* p) {
  if(p[0] == '\0') { return s[0] == '\0'; }
  if(p[1] != '*') { // 如不是*就必须匹配
    if(s[0] != '\0' && (s[0] == p[0] || p[0] == '.')) { // s[0] != '\0'因为比如s="", p="."
      return isMatch(s + 1, p + 1);
    } else {
      return false;
    }
  } else {
    int i = 0;
    while(s[i] != '\0' && (s[i] == p[0] || p[0] == '.')) {
      if(isMatch(s + i, p + 2)) { return true; } // 不匹配这一个
      i ++; // 匹配这一个
    }
    return isMatch(s+i, p+2);
  }
}
