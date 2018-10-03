include(common.m4)dnl
define(`cg', `ifelse(eval($1), eval($2), `return $1;',
if (arr[eval(($1+$2)/2)] < target) {
`cg(eval((($1+$2)/2)+1), $2)'
} else {
`cg($1, eval(($1+$2)/2))'
})')dnl

#pragma once
#include "data.h"

int code_gen_search(float target) {
cg(0, size_array - 1)

}
