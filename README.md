#Brief & Throught Process
After started from Brueforce way to calculate Edit distance between 1000 input Strings to dict (which is 82K english corpos) it took `8min` to run :(. After reasearching a bit about all the algorithms i pick symmetric deletion algorithm and added my optimizations to move further as it is then most Practical way (spell checkers in real life never suggests a large varient of the misspelled words it makes sense to fix the max length varient i.e Edit distance) to tackle this problem statement.

## how symmetric deletion algorithm works?
In symmetric deletion algorithm, a data structure is described to efficiently handle lookups of words within a certain Levenshtein (or Damerau-Levenshtein) distance from a given word. The structure is based on a map where each key represents a word with one or more letters removed (variants), and the corresponding value is a list of original words that match that variant.

For instance, given the dictionary words ["apple", "pear", "peach"] and the requirement to support Levenshtein distance <= 1:

Variants of "apple" with one letter removed: "aple", "appe", "appl", "apple", "pple"
Variants of "pear" with one letter removed: "par", "per", "pea", "pear", "ear"
Variants of "peach" with one letter removed: "peah", "peac", "pech", "peah", "each", "peach"
These variants are stored in the map along with their corresponding original words.

For a lookup operation, the input word undergoes the same transformation to generate its variants. Each variant is then looked up in the map to retrieve a list of candidate original words. The Levenshtein distance (or Damerau-Levenshtein distance) between the input word and each candidate word is calculated to confirm their similarity. If the distance is within the specified threshold (in this case, <= 1), the candidate word is considered a match.

For example, if "pearh" is the word being looked up, its variants are ["pearh", "earh", "parh", "perh", "peah", "pear"]. After looking up each variant, matches are found for "peah" (maps to "peach") and "pear" (maps to "pear"). Confirming that the Levenshtein distance between "pearh" and "peach" is 1 and between "pearh" and "pear" is also 1, both "peach" and "pear" are confirmed as legitimate matches.




### How to Run 
1. download foler
2. run main.cpp


## Results

With editdistance as `4` Time for 1000 words is  `0.753` Seconds with an accuracy of `98.13 %`

<img width="564" alt="Screenshot 2024-02-15 at 9 42 24 PM" src="https://github.com/akhiltej-2514/Blinkit_Challange/assets/74290451/a23fcd8f-ce4c-4c0a-95cf-0214a4967a37">



With editdistance as `3` Time for 1000 words is  `0.194` Seconds with an accuracy of `94.53 %`

<img width="564" alt="Screenshot 2024-02-15 at 10 07 23 PM" src="https://github.com/akhiltej-2514/Blinkit_Challange/assets/74290451/e972cb79-96a2-4cb9-aa46-4823b7d7a236">


##Futher Improvements which can deal a 30L+ entries.
1.Using a Highly Efficient HashMap like `Dense_hash_map` by Google. which are more faster than inbuilt unordered_maps.
2.Making multhreaded version.
