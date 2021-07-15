/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题3（一）：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。

#include <cstdio>

// 参数:
//        numbers:     一个整数数组
//        length:      数组的长度
//        duplication: (输出) 数组中的一个重复的数字
// 返回值:             
//        true  - 输入有效，并且数组中存在重复的数字
//        false - 输入无效，或者数组中没有重复的数字
bool duplicate(int numbers[], int length, int* duplication)
{
    // 检查数组是否为空
    if(numbers == nullptr || length <= 0)
        return false;

    // 检查数组中是否包含0~n-1以外的数字
    for(int i = 0; i < length; ++i)
    {
        if(numbers[i] < 0 || numbers[i] > length - 1)
            return false;
    }

    for(int i = 0; i < length; ++i)
    {
        // 1.首先比较 下标i的数字numbers[i] 是不是等于 i
        while(numbers[i] != i)  // 如果不等于i，进行下一步判断；等于i直接跳过
        {
            // 2.再拿 numbers[i] 和 下标numbers[i]的数字numbers[numbers[i]] 进行比较
            if(numbers[i] == numbers[numbers[i]])
            {
                // 如果相等则找到一个重复的数字
                *duplication = numbers[i];
                return true;
            }

            // 如果不相等，交换numbers[i]和numbers[numbers[i]]       
            int temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;
            // 3.重复1和2，直到numbers[i] == i
        }
    }

    return false;
}

/********************************************************************************************************
描述:
        测试duplicate函数找到的重复数字是否正确
参数:
        array：     数组中所有重复数字组成的数组
        length：    重复数字的个数
        number：    duplicate函数检测到的重复数字
返回值:
        true：      检测正确
        false：     检测错误
********************************************************************************************************/
bool contains(int array[], int length, int number)
{
    for(int i = 0; i < length; ++i)
    {
        if(array[i] == number)
            return true;
    }

    return false;
}

/********************************************************************************************************
描述:
        测试一个数组是否有重复数字
参数:
        testName：          第几个测试
        numbers：           要测试的数组
        lengthNumbers：     要测试的数组长度
        expected：          数组中的重复数字组成的数组
        expectedExpected：  重复数字的个数
        validArgument：     true表示数组中有重复数字，false表示没有或输入无效
返回值:
        无
********************************************************************************************************/
void test(char* testName, int numbers[], int lengthNumbers, int expected[], int expectedExpected, bool validArgument)
{
    printf("%s begins: ", testName);

    int duplication; // 存放返回的重复数字
    bool validInput = duplicate(numbers, lengthNumbers, &duplication);

    // 判断检测结果是否正确
    if(validArgument == validInput)
    {
        if(validArgument)
        {
            if(contains(expected, expectedExpected, duplication))
                printf("Passed.\n");
            else
                printf("FAILED.\n");
        }
        else
            printf("Passed.\n");
    }
    else
        printf("FAILED.\n");
}

// ====================测试代码====================
// 重复的数字是数组中最小的数字
void test1()
{
    int numbers[] = { 2, 1, 3, 1, 4 };
    int duplications[] = { 1 };
    test("Test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 重复的数字是数组中最大的数字
void test2()
{
    int numbers[] = { 2, 4, 3, 1, 4 };
    int duplications[] = { 4 };
    test("Test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 数组中存在多个重复的数字
void test3()
{
    int numbers[] = { 2, 4, 2, 1, 4 };
    int duplications[] = { 2, 4 };
    test("Test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 没有重复的数字
void test4()
{
    int numbers[] = { 2, 1, 3, 0, 4 };
    int duplications[] = { -1 }; // not in use in the test function
    test("Test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 没有重复的数字
void test5()
{
    int numbers[] = { 2, 1, 3, 5, 4 };
    int duplications[] = { -1 }; // not in use in the test function
    test("Test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 无效的输入
void test6()
{
    int* numbers = nullptr;
    int duplications[] = { -1 }; // not in use in the test function
    test("Test6", numbers, 0, duplications, sizeof(duplications) / sizeof(int), false);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

    return 0;
}