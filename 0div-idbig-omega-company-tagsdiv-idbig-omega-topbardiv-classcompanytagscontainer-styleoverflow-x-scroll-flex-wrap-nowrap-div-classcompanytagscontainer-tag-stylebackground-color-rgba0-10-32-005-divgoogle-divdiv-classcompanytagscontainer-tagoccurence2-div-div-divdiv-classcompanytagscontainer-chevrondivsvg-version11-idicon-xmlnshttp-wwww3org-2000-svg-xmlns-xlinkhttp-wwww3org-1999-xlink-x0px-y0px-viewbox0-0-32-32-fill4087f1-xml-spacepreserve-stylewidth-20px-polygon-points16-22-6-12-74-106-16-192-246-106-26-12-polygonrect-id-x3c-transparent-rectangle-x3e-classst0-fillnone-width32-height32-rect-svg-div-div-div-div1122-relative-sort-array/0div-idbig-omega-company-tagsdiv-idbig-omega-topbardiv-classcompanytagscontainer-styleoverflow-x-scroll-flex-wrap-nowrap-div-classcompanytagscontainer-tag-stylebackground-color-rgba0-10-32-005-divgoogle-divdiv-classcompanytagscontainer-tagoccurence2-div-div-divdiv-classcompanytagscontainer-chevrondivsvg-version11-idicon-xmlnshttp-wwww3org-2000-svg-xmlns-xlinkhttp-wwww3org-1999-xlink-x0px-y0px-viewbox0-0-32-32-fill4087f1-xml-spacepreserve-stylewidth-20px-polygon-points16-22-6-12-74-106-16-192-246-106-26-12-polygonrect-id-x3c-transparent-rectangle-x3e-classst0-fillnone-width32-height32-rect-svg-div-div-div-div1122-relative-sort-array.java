class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int m = arr1.length;
        
        TreeMap<Integer, Integer> mp = new TreeMap<>();
        for(int i=0; i<m; i++){
            if(mp.containsKey(arr1[i])) mp.put(arr1[i], mp.get(arr1[i])+1);
            else mp.put(arr1[i], 1);
        }
        
        int index = 0;
        for(int i=0; i<arr2.length; i++){
            int count = mp.get(arr2[i]);
            while(count > 0){
                arr1[index++] = arr2[i];
                count--;
            }
            mp.remove(arr2[i]);
        }
        for(Map.Entry<Integer,Integer> entry : mp.entrySet()){
            int count = entry.getValue();
            while(count > 0){
                arr1[index++] = entry.getKey();
                count--;
            }
        }
        return arr1;
    }
}