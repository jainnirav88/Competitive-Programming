Tutorial link: https://docs.google.com/document/d/1O1WCZQtjlKFpJuB59x7TuPWD0XQ3oElOKg2Z_7EZgJ0/edit#

Other: https://youtu.be/JXTVOyQpSGM, https://codeforces.com/blog/entry/78985, https://ali-ibrahim137.github.io/competitive/programming/2020/08/23/Stress-Testing.html

=> Source: 

-> From someone's git repo, I forgot the name

=> Process:

-> Copy and paste your efficient solution (the one which is failing) in the efficient.cpp file and copy and paste your naive solution (the one which is brute-force)(someone else's solution which is correct in case of practice) in the naive.cpp file

=> Generator (generator.cpp)

-> Complete the make_test function in the generator.cpp file based on the input format given

=> Tips

-> Generate small range input first (through generator) as it helps in finding the mistake/error in code faster

=> Common mistakes: 

-> Using the same solution for both efficient.cpp and naive.cpp
-> Out of bound value in the input (Make sure you are generator generates the input according to the range given in the constraints of problem)
-> Wrong input format. (Make sure you maintain the input format)

=> How much time: 

-> 2-3 minute for writing the brute-force
-> 2-5 minute for writing the generator
-> 2-30 minute for the finding the test-case where your solution fails

=> When to use: 

-> When there are no other options left
-> You should check common types of errors first and then opt for the stress testing
-> Although, you can use it in the contest but consider doing it very very fast and try to write an efficient generator (Like thinking about the test case where your solution might fail and producing that type of input)

=> How to write an efficient generator?

-> later...

=> How to find the failing test case?

-> later...
