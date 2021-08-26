
//Strobogrammatic numbers of length n

public ArrayList<String> strobogrammatic(int n) {
  HashMap<String, String> stroboMap = new HashMap<>();
  stroboMap.put("1", "1");
  stroboMap.put("0", "0");
  stroboMap.put("8", "8");
  stroboMap.put("6", "9");
  stroboMap.put("9", "6");
  ArrayList<String> result = new ArrayList<String>();
  stroboHelper(result, n, new StringBuilder());
  return result;
}

//Actually doesn't work in middle
public void stroboHelper(ArrayList<String> result, int n,
    StringBuilder sb, HashMap<String, String> stroboMap) {
      int wordLength = sb.length();
      if(wordLength == n) {
        result.add(sb.toString());
        return;
      }

      if(wordLength == n/2 && n % 2 != 0) {
        String [] candidates = new String[] {"1", "8", "0"};
        for(String s: candidates) {
          sb.append(s);
          stroboHelper(result, n, sb, stroboMap);
          sb.setLength(sb.length() - 1);
        }
      } else if(wordLength >= n/2) {
        char rotatedChar = sb.charAt(n - 1 - wordLength);
        sb.append(stroboMap.get(String.valueOf(rotatedChar)));
        stroboHelper(result, n, sb, stroboMap);
        sb.setLength(sb.length() - 1);
      } else {
        for(String s: stroboMap.keySet()) {
          sb.append(s);
          stroboHelper(result, n, sb, stroboMap);
          sb.setLength(sb.length() - 1);
        }
      }
}
