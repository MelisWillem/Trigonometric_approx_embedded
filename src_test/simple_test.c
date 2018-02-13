#include "stdio.h"
#include "../src/globals.h"
#include "../src/cos_sin.h"
#include "math.h"

#define NUMBER_OF_TESTS 200
#define MIN_TEST -TWOPI
#define MAX_TEST TWOPI

static int test_accuracy( real_t (*std_lib)(real_t), real_t (*function_to_test)(real_t),
                                        int number_of_digits);
static int test_cosine(void);
static int test_sine(void);

int main(void){/* int argc,char** args */
    return test_cosine()+test_sine();
}
static void print_test_title(int number_of_digits){
    printf("-> testing accuracy of about %d digits: \n",number_of_digits);
}
static int test_cosine(void){
    printf("Testing cosine functions:\n");
    int return_value=0;

    const int digits_accuracy_cos_32 = 3;
    print_test_title(digits_accuracy_cos_32);
    return_value += test_accuracy(cos,cos_32,digits_accuracy_cos_32);

    const int digits_accuracy_cos_52 = 5;
    print_test_title(digits_accuracy_cos_52);
    return_value += test_accuracy(cos,cos_52,digits_accuracy_cos_52);

    const int digits_accuracy_cos_73 = 7;
    print_test_title(digits_accuracy_cos_73);
    return_value += test_accuracy(cos,cos_73,digits_accuracy_cos_73);

    const int digits_accuracy_cos_121 = 12;
    print_test_title(digits_accuracy_cos_121);
    return_value += test_accuracy(cos,cos_121,digits_accuracy_cos_121);

    return return_value;
}
static int test_sine(void){
    const int digits_accuracy_sin_32 = 3;
    return test_accuracy(sin,sin_32,digits_accuracy_sin_32);
}
static int test_accuracy( real_t (*std_lib)(real_t), real_t (*function_to_test)(real_t),
                                        int number_of_digits){
    int i;
    for (i = 0; i < NUMBER_OF_TESTS; i++)
    {
        real_t x = i*((MAX_TEST - MIN_TEST)/NUMBER_OF_TESTS + MIN_TEST);
        real_t std_cos = std_lib(x);
        real_t test_value = function_to_test(x);

        real_t difference = ABS(std_cos-test_value);
        real_t max_error = pow(10,-number_of_digits);

        if(difference>max_error){
            printf("--> error in calculating x with index i=%d \n",i);
            return FAILURE;
        }
    }
    return SUCCESS;
}