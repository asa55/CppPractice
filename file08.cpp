#include <iostream>
#include <algorithm>
//generally don't suck at the core language
//templates
//operator overloading
//preprocessor statements and macros
//namespaces
//exceptions
//const and mutable (and friend functions)
//static and dynamic casting
//pointers / void pointers / smart pointers
//enums
//string streams
//virtual functions and virtual inheritance and vtables
//runtime type information (RTTI)
//Qt, OpenGL, TensorFlow, OpenCV, Eigen, Drake
//STL <vector> <unordered_map> other containers <string> <chrono> <thread> <mutex> - - actually containers , the algorithms over them , and the iterators that connect them are best explained by Bo Qian's YouTube playlist
//visual studio debug tools (breakpoints, memory view)
//package management
//any frameworks at all would be great
//gtest (anything for unit testing)
//makefiles - building code (compiling, linking, anything extra?)
//deploying bare-metal, including Python, running on an OS or with Board Support Packages
//programming paradigms
//    memory allocation as initialization
//    don't use casts
//    avoid naked new and naked delete
//    avoid macros except for include guards
//    if you have any doubts about th evalidity of a pointer, use a smart pointer instead
//    avoid unions
//    hide void* in low-level, and only if needed
//    hide arrays from interfaces, keep them in low-level if needed
//    prefer immutable to mutable data
//    encapsulate messy constructs rather than spreading them thru the code
//    interfaces are the single most important aspect of code organization, make them explicit, encapsulate rule violations
//    state preconditions, prefer Expects() for expressing preconditions and Ensures() for postconditions
//    prefer <vector> by default, prefer <array> to C-style arrays if needed
//C++98 added templates, containers, <algorithm>, <string>, <iostream>
//C++11 added auto, function pointers / lambdas, multithreading, regexp, smart pointers, hash tables
//C++14 addded read-write locks, generic lambdas
//C++17 added parallel algorithms
//C++20 will add coroutines, modules, concepts, ranges lib, spaceship operator, and will deprecate contracts

// I think it's critical that I watch Cherno's game engine series, get really good at Eigen and now start diving into ROS

//C++ quizzes and leetcode
//Bjarne Stroustrup and www.stroustrup.com/C++.html
//    https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md
//  https://towardsdatascience.com/algorithms-in-c-62b607a6131d

// Know that REPL.it or coderpad exist - I know you'll probably want to set up a local shell or environment so get gcc and use the commands I use. But this is secondary to getting a grip on the semantics of the language.
// Step 1 to learning C++ ... just go over the bare bones basics and discuss types you'd expect but need to include, and ranged for's, and the lack of need for brackets.
// Next I'd mention that C++ like all languages evolves according to written standards. C++98 was the old C++, C++11, C++14, C++17 are called modern C++ and you should know that they're mostly identical for new users, but C++20 is a new major revision and will add functionality you need to know about like spaceship operators and templated lambdas.
// The next thing I'd say is that if you took an intro to not-C++ course, you'll feel in the dark by the time you finish a standard C++ course, because the above minus ranged fors is all it goes over.
// The next thing I'd mention is Eigen - it's super satisfying to be able to do normal operations. If you're a Matlab person, you'll feel so at home after this.
// Next watch the Cherno's C++ playlist. This goes over most of the concepts that get you through the steep learning curve that is unique to C++.
// Next it's great to know inventor of C++, supergenius and generally good-guy Bjarne Stroustrup is still around to guide us. He is on our side and has great insights. Listen to him speak to get some context about where C++ is and where it's headed. I feel this gives great context regarding some of the design decisions and how we can think symbiotically with the mindset used to create the language.
// You'll still feel left in the dark after this point - if you want to use non-trivial data structures the likes of which we all learned in MIT 6.0001 for Python, we'll need to understand the standard library and in particular STL. Bo Qian's playlist helps a lot with this.
// You'll notice there is a lot to learn in C++ and when it comes to engineering, I can't underemphasize how good you'll look if you know the right tools for the right jobs.
// But in order to land a job at all, chances are you'll need to pass a coding interview. I had 6 at once and saw various tiers of questions.
// I'd say if you use the shotgun approach like I did, you're going to get the same results. There are people who want to know if you have solid data science knowledge in whatever language, and ones who want to have a degree of confidence you can write production quality code in your language of choice.
// Cppquiz is good for the nitty gritty details of C++, otherwise look to language agnostic code quesitons by searching "code interview questions" on google. you'll get lists of everyones favorites, and by this point you'll know more than needed to answer all the questions at least one way.
// There are also the embedded aspects - we need to be able to target hardware and cross-compile for it. Get Atmel studio and an Arduino - you'll at least be able to program it via the onboard USB bootloader. An upgrade would be to buy an Atmel programming cable and go ham on bare metal.

struct Item{
    int value, weight;
    Item(int value, int weight) : value(value), weight(weight) {}
}; 
bool cmp(struct Item a, struct Item b){ 
    double r1 = (double) a.value / a.weight; 
    double r2 = (double) b.value / b.weight; 
    return r1 > r2;
} 
double fractional_knapsack(int W, struct Item arr[], int n)
{
    sort(arr, arr + n, cmp); 
    int cur_weight = 0; double tot_value = 0.0;
    for (int i=0; i < n; ++i) 
    { 
        if (cur_weight + arr[i].weight <= W) 
        {
            cur_weight += arr[i].weight;
            tot_value += arr[i].value;
        }   
        else 
        {   //add a fraction of the next item
            int rem_weight = W - cur_weight;
            tot_value += arr[i].value * 
                        ((double) rem_weight / arr[i].weight);                     
            break;
        }
    } 
    return tot_value;
}
int main()
{ 
    int W = 50; // total knapsack weight
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}}; //{value, weight}
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "greedy fractional knapsack" << endl; 
    cout << "maximum value: " << fractional_knapsack(W, arr, n);
    cout << endl; 
    return 0;
}