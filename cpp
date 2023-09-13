class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
        int m = s1.length();
    int n = s2.length();
    
    // Handle signs
    int sign = 1;
    if (s1[0] == '-') {
        sign *= -1;
        s1 = s1.substr(1);
        m--;
    }
    if (s2[0] == '-') {
        sign *= -1;
        s2 = s2.substr(1);
        n--;
    }
    
    // Initialize result array and fill with zeros
    int resultSize = m + n;
    int* result = new int[resultSize]();
    
    // Perform multiplication
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int num1 = s1[i] - '0';
            int num2 = s2[j] - '0';
            int mul = num1 * num2;
            
            int sum = mul + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }
    
    // Convert result array to string
    string product = "";
    int i = 0;
    while (i < resultSize && result[i] == 0) {
        i++;
    }
    
    if (i == resultSize) {
        return "0";
    }
    
    while (i < resultSize) {
        product += to_string(result[i++]);
    }
    
    delete[] result;
    
    return sign == -1 ? "-" + product : product;
}
    

};
