class Solution {
    public int findSpecialInteger(int[] arr) {
        int n = arr.length;
        int f = (int) (0.25 * n);
        HashMap<Integer, Integer> mp = new HashMap<>();
        for(int i=0; i<n; i++){
            if(mp.containsKey(arr[i])){
                int count = mp.get(arr[i]);
                mp.put(arr[i], count+1);
            }
            else mp.put(arr[i], 1);
        }
        for(Map.Entry<Integer, Integer> p : mp.entrySet()){
            if(p.getValue() > f) return p.getKey();
        }
        return 0;
    }
}