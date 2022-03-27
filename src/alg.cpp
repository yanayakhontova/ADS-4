// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int c = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value)
        c += 1;
    }
  }
  return c;
}
int countPairs2(int *arr, int len, int value) {
  int c = 0;
  int t;
  for (int i = len - 1; i >= 0; i--) {
    if (arr[i] > value) {
      continue;
    } else {
      t = i;
      break;
    }
  }
  for (int i = 0; i < t - 1; i++) {
    for (int j = t; j >= i + 1; j--) {
      if (arr[i] + arr[j] == value)
        c++;
    }
  }
  return c;
}
int countPairs3(int *arr, int len, int value) {
  int c = 0, L = 0, R = len - 1;
  while (L < R - 1) {
    int m_1 = (L + R) / 2;
    if (arr[m_1] <= value)
      L = m_1;
    else
      R = m_1;
  }
  len = R - 1;
  for (int i = 0; i < len; i++) {
    L = i + 1, R = len - 1;
    int w = 0;
    while (L < R) {
      int m_2 = (L + R) / 2;
      if (arr[m_2] < (value - arr[i]))
        L = m_2 + 1;
      else
        R = m_2;
    }
    while (arr[L] == (value - arr[i])) {
      w++;
      L++;
    }
    c += w;
  }
  return c;
}
