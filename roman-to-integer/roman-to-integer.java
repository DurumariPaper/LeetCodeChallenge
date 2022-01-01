class Solution {
    
    static Map<String, Integer> values = new HashMap<>();
    
    static {
        values.put("M", 1000);
        values.put("D", 500);
        values.put("C", 100);
        values.put("L", 50);
        values.put("X", 10);
        values.put("V", 5);
        values.put("I", 1);
    }
    
    public int romanToInt(String s) {
        int size = s.length();
        String lastSymbol = s.substring(size - 1);
        int sum = values.get(lastSymbol);
        int prevValue = sum;
        for(int i = s.length() - 2; i >= 0 ; --i)
        {
            String currentSymbol = s.substring(i, i+1);
            int currentValue = values.get(currentSymbol);
            if(prevValue <= currentValue)
            {
                sum += currentValue;
                prevValue = currentValue;
            }
            else
            {
                sum -= currentValue;
            }
        }
        
        return sum;
    }
}