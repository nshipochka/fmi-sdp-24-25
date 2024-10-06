# Сложност
**Сложността по време** е мярка, която ни казва как нараства времето за изпълнение на даден алгоритъм, когато  големината на входа му клони към *безкрайност*.  

**Сложността по памет** е мярка, която ни казва как нараства паметта, която даден алгоритъм ползва, когато големината на входа му клони към *безкрайност*.  

## Big O Notation
Ще разглеждаме нестрога асимптотична горна граница
`O(f) = { g | g ≼ f }`
- `g ≼ f` означава, че `g` расте не по-бързо от `f`
- `O(f)` е множеството от всички функции, които растат не по-бързо от `f` 

*Има и други нотации - `Θ (Big-Theta)`, `Ω (Big Omega)`, `o (Small Oh)`, `ω (Small Omega)`. Нас най-често ни интересува `O` нотацията, защото ако `g = O(f)`, то `f` в някакъв смисъл е възможно най-лошото (по големина) приближение до `g`.*


### Правила за пресмятане на сложност
- `O(c * f) = O(f)`, където `c` е константа
- `О(f + g) = max{ O(f), O(g) }`
- `O(f * g) = O(f) * O(g)`
- `O(f) = O(g)` <=> Съществува константа `c > 0`, такава, че `f = c * g`

## Основните [сложности](https://www.bigocheatsheet.com/) с примери

1) `O(c)` или `O(1)` - константна сложност, `c` - константа 

    Почти пренебрежимо влияние върху сложността, обикновено е елементарна операция, независеща от обема на входните данни   

    **Примери:**    
    - деклариране, въвеждане, извеждане на променливи
    - оператора `if`
    - извикване на функция
    - ```c++
        int average(int first, int second) {
            return (first + second) / 2;
        }
      ```

2) `O(log(n))` - логаритмична сложност  

    Най-ниската стойност за сложност, която зависи от n.    

    **Примери:**    
    - двоично търсене
    - `for(size_t i = 1; i <= n; i *= 2)` - променливата на цикъла расте експоненциално, значи времето за изпълнение става логаритмично

3) `O(n)` - линейна сложност    
    
    **Примери:**    
    - обхождане на масив
    - линейно търсене
    -   ```c++
        int factorial(unsigned n) {
            unsigned res = 1;
            for(unsigned i = 1; i <= n; i++)
                res *= i;

            return res;
        }
        ```

4) `O(n * log(n))` - линейно-логаритмична сложност  

    Най-бързото сортиране в общия случай е с такава сложност    

    **Примери:**    
    - merge sort
    -   ```c++
        void print_indexes(vector<int>& arr) {
            size_t size = arr.size();
            for (int i = 0; i < size; i++) 
                std::cout << binary_search(arr, 0, size - 1, arr[i]);
        }
        ```

5) `O(n^2)` - квадратична сложност  

    **Примери:**    
    - обхождане на матрица
    - bubble sort, selection sort, insertion sort
    -   ```c++
        void print_pairs(vector<int>& arr, size_t size) {
            for (int i = 0; i < size; i++)   
                for (int j = 0; j < size; j++) 
                    std::cout << arr[i] << " " << arr[j] << std::endl;
        }
        ```

6) `O(n^3)` - кубична сложност  

    Обикновено тази сложност се разглежда като последната приемлива за практически приложим алгоритъм   

    **Примери:**    
    - Белман-Форд

7) `О(2^n)` - експоненциална сложност   

    **Примери:**    
    ```c++
    //O(1.618^n) - експоненциална сложност с основа phi
    int fibonacci(int n) { 
        if (n <= 0) 
            return 0; 

        else if (n == 1) 
            return 1; 

        else 
            return fibonacci(n - 1) + fibonacci(n - 2); 
    }
    ```

8) `O(n!)` - факториелна сложност

## Защо е важно?

| n | O(1) | O(log n) | O(n) | O(n log n) | O($n^2$) | O($2^n$) | O(n!)
| - | - | - | - | - | - | - | - 
| 1	        | < 1 sec |	< 1 sec |	< 1 sec	| < 1 sec	| < 1 sec	| < 1 sec	            | < 1 sec
| 10	        | < 1 sec |	< 1 sec |	< 1 sec	| < 1 sec	| < 1 sec	| < 1 sec	            | 4 sec
| 100	        | < 1 sec |	< 1 sec |	< 1 sec	| < 1 sec	| < 1 sec	| 40170 trillion years	| > vigintillion years
| 1,000	    | < 1 sec |	< 1 sec |	< 1 sec	| < 1 sec	| < 1 sec	| > vigintillion years	| > centillion years
| 10,000	    | < 1 sec |	< 1 sec |	< 1 sec	| < 1 sec	| 2 min	    | > centillion years	| > centillion years
| 100,000	    | < 1 sec |	< 1 sec |	< 1 sec	| 1 sec	    | 3 hours	| > centillion years	| > centillion years
| 1,000,000	| < 1 sec |	< 1 sec |	1 sec	| 20 sec	| 12 days	| > centillion years	| > centillion years

# Задачи
### [Move Zeros](https://leetcode.com/problems/move-zeroes/)
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array. 

```    
Input: nums = [0,1,0,3,12]  
Output: [1,3,12,0,0] 
``` 
```
Input: nums = [0]   
Output: [0] 
```
Constraints:
```
1 <= nums.length <= 104 -231 <= nums[i] <= 231 - 1
```


### [Plus One](https://leetcode.com/problems/plus-one/) 
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.   

Increment the large integer by one and return the resulting array of digits.    

```
Input: digits = [1,2,3] 
Output: [1,2,4]     
Explanation: The array represents the integer 123. Incrementing by one gives 123 + 1 = 124. Thus, the result should be [1,2,4]. 
```
```
Input: digits = [4,3,2,1]   
Output: [4,3,2,2]   
Explanation: The array represents the integer 4321. Incrementing by one gives 4321 + 1 = 4322. Thus, the result should be [4,3,2,2].    
```
```
Input: digits = [9]     
Output: [1,0]   
Explanation: The array represents the integer 9. Incrementing by one gives 9 + 1 = 10. Thus, the result should be [1,0].    
```
Constraints:    
```
1 <= digits.length <= 100 0 <= digits[i] <= 9 digits does not contain any leading 0's.   
```

### [Rotate Image](https://leetcode.com/problems/rotate-image/)
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise). 

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.  
 
```
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]   
Output: [[7,4,1],[8,5,2],[9,6,3]]   
```
```  
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]    
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]    
```
Constraints:    
```
n == matrix.length == matrix[i].length 1 <= n <= 20 -1000 <= matrix[i][j] <= 1000   
```