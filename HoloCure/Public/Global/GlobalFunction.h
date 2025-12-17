#pragma once

#define CRASH(cause) { std::abort();}
#define ASSERT_CRASH(expr){	if (!(expr)) {CRASH("ASSERT_CRASH");__analysis_assume(expr);}}
