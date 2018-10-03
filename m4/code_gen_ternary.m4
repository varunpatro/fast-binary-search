include(common.m4)dnl
define(`cg', `ifelse(eval($1), eval($2), `$1',
(arr[eval(($1+$2)/2)] < target)
?
`cg(eval((($1+$2)/2)+1), $2)'
:
`cg($1, eval(($1+$2)/2))')')dnl

#pragma once
#include "data.h"

int code_gen_ternary_search(float target) {
return cg(0, size_array - 1);

}
