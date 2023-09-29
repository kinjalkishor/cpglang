{-
#include <stdio.h>
int main(void) {
	printf("Hello World!\n");
	return 0;
}
-}

import cstdlib.stdio;
fn main(): i32 {
	print("Hello World!\n");
	return 0;
}

// hello world
/* hello world */
{- hello world -}
//---------------------------

var a i32;
var a const i32;
var a i32^;
var a i32!^;
var a const i32^;
var a const i32!^;
var b i32& = a&;


var pa i32^ = a&;
var a i32 = pa^;
var ppa i32^^ = pa&;

fn sum(s i32&, a i32!&, b i32!&): void {
	s = a + b;
}

fn sum(a vec3^): int {
	return a^.x + a^.y + a^.z;
}

fn swap(a i32^, b i32^): void {
	var t i32 = a^;
	a^ = b^;
	b^ = t;
}



//----------------
var a i32 = 5;
var a i32 = u_;
var b f32 = 2.5;

var len256 constexpr i32 = 256;
var len_max constexpr i32 = comptime multiply(4, 5);


inline fn sum(a i32, b i32): i32 {}
private fn sum(a i32, b i32): i32 {}

fn sum(a i32, b i32): i32 {
	return a + b;
}

fn sum_diff(a i32, b i32): i32, i32 {
	return a + b, a - b;
}
var s, d = sum_diff(3, 2);


var b [3]i32;
var q [3]i32^;

int a[_] = [0, 1, 2, 3, 4, 5];
//------------
type angle f32;

// func ptr, fnp
type pft_sum fnp(i32, i32): i32;
//var fp pft_sum = sum;
var fp pft_sum;
fp = sum;

//i32 (*fp)(i32, i32)
var fp fnp(i32, i32): i32;
//int (*fp)(int (*)(int, int), int)
var fp fnp((fnp(i32, i32): i32), i32): i32
//int (*(*fp)(int (*)(int, int), int))(int, int)
//f func(func(int,int) int, int) func(int, int) int
var fp2 fnp(fnp(i32, i32): i32, i32): fnp(i32, i32): i32
type ff fnp(i32, i32): i32;
var fp2 fnp(ff, i32): ff;

fn do_something(doer fnp(i32, i32): i32) {
	doer(5,5);
}
do_something(&add);

// closure
// lambda
// [=] by value, [&] by ref
// [=, m] except m others by value, [&, m] except m others by ref
// [m, &n] only m by value and n by ref captured

fn main(): void {
   var m i32 = 0;
   var n i32 = 0;
   
   // explicitly captures the variable m by reference and others by value.
   var c i32 = lambda eval [=, m&](a i32, b i32): i32 { 
		n++; 
		m = n+1; 
		return a + b + m + n;
   }(3, 4);	
	// m = 1, n = 0, c = 10 (3 + 4 + 2 + 1)
	
	var x i32 = 5;
	fn inner = lambda [x](y i32): i32 {
        return x + y;
    };
	var v = inner(6); // v = 11 (5 + 6)
}

template<type T>
sort(std::array!<T>, lambda [](a T, b T): bool { return a < b; });

// inner functions. function local scope is like global for inner function.
fn outer(): void {
	var x: string = "before";
	fn inner = lambda [x&](): void {
		x = "assigned";
	}
	inner();
	fmt.println(x);
}
outer(); // prints assigned


//------------
//vec3 a(1, 2, 3);
var a vec3;
var a = vec3(1, 2, 3);

//std::vector<i32> a(10);
var a std::vector!<i32>(10);
var vec1 = std::vector!<i32>[1, 2, 3];

var a std::vector[i32](10);
var a hash_map!<shape, pair!<string, string>>;

var b f32 = 1.0 scast f32 - 2.0 scast f32 + x * y;
//var b f32 = scast!<f32>(1.0) - scast!<f32>(2.0) + x * y;
var c = (1.0 - 2.0) scast f32;
//var c = scast!<f32>(1.0 - 2.0);
//var a char^ = scast!<char^>(malloc(sizeof(char)*3));
var a char^ = malloc(sizeof(char)*3) scast char^;

template!<type T>
fn add(a T , b T): T { return a + b; }
add!<i32>(3, 4);

template!<type T extern f32, f64>
fn add(a T , b T): T { return a + b; }
add!<f32>(3, 4);
t.bar!<3>();


//------------------------
type vec2 struct {
	x f32 = 0.0;
	y f32 = 0.0;
	
	constructor default(self^): self {
		x = 0.0;
		y = 0.0;
		return self;
	}
	
	constructor create(self^, f f32): self {
		x = f;
		y = f;
		return self;
	}
	
	constructor create(self^, xa f32, ya f32): self {
		x = xa;
		y = ya;
		return self;
	}
	
	constructor unit(self^): self {
		x = 1.0;
		y = 1.0;
		return self;
	}

	destructor(self^): void {
		x = 0.0;
		y = 0.0;
	}		

	fn set(self^, f f32): void {
		x = f;
		y = f;
	}
	
	//static modify static variables, static const cannot modify static variables.
	static const fn size(): i32 {
		return 2;
	}
	
	fn length(self!^): f32 {
		return 1.0 scast f32;
	}
};

fn length(a vec2!^): f32 {
	return 1.0 scast f32;
}

var len = a.length();
var len = a.length!(); //ufcs
var dim = vec2::size();

var pa vec2^ = allocate(1);
construct_at(1, pa, vec2(1, 2));
var pa vec2^ = allocate_construct(1);
var pa vec2^ = allocate_construct(1, vec2.create(1, 2));
var pa vec2^ = allocate_construct(1, vec2.unit());
pa^.x = 3;
var b = pa^.length();
//pa^.destroy();
destruct_at(1, pa);
deallocate(1, pa);
deallocate_destruct(1, pa);


type A struct {
    virtual fn def(): i32 { ... }
    fn foo(): i32 { ... }
    private fn bar(): i32 { ... }
    private fn abc(): i32 { ... }
}

type B struct : A {
    override int def() { ... }  // ok, overrides A.def
    //override int foo() { ... }  // error, A.foo is non virtual
    fn bar(): i32 { ... }  // ok, A.bar is private, but non virtual, B.bar is non virtual & public
    virtual fn abc(): i32 { ... }  // ok, A.abc is non virtual, B.abc is virtual & public
}

void test() {
    a A^ = allocate_construct!<B>(1) dcast A^;
    a^.def();    // calls B.def
    a^.foo();    // calls A.foo
    a^.bar();    // calls A.bar
    a^.abc();    // calls A.abc
	
	b B^ = allocate_construct(1);
	b^.foo();
	b^.A::foo();
	b^.super::foo();
}

//---------------------------------
type bg_color enum i32 {
	red, 
	green,
	blue,
};
var c bg_color = bg_color::red;

type scolor enum_weak i32 {
	red, 
	green,
	blue,
}:
var ci i32 = scolor::red;

//---
// match (switch is only for int)
fn col_to_val(col bg_color): i32 {
    return match(col) {
        ::red    => 1,
		::green  => 2,
        ::blue   => 3,
		default  => 0,
    };
}

fn display_val(number i32): void {
    return match(number) {
        1 => println!("One!"),
        2 | 3 | 5 | 7 | 11 => println!("This is a prime"),
        13 to 19 => println!("A teen"),
        default => println!("Ain't special"),
    };
}
//---------------------------------
if (a=1 and b=2) {
	return true;
} else {
	return false;
}

var c = if_exp (a>2) {
	true
} else {
	false
};

//---------------------------------
var i i32 = 0;
while (i < 100) {
	x = x + 1;
	i = i + 1;
}
//return x;

var i i32 = 0;
do {
	x = x + 1;
	i = i + 1;
} while (i < 100);
//return x;
//---------------------------------

for (var i i32 = 0; i < 5; i++) {
	i = 0;
}

// 0, 1, 2, 3, 4
for (var i i32 in (0, 5)) {
	i = 0;
}
// 4, 3, 2, 1, 0
for (var i i32 in rev (0, 5)) {
	i = 0;
}

for (var i i32 in (4, -1, -1)) {
	i = 0;
}

for (var n i32 in [ 0, 1, 2, 3, 4, 5 ]) {
	fmt.println(x);
}

std::string str = "hello";
for (var c char in str) {
	fmt.println(c);
}

for (var x in array) {
	fmt.println(x);
}

for (var x in rev array) {
	fmt.println(x);
}

std::map!<i32, i32> amap({ { 1, 1 }, { 2, 2 }, { 3, 3 } });
for (var i in amap) {
	//fmt.println("_{{i.first}, {i.second}_}");
	fmt.println("{_$(i.first), _$(i.second)}");	
}

//fmt.println("a = {a}");
fmt.println("a = _$[8:6:f](a)");
