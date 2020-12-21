let M = 1_000_000_007'i32;
proc `++`(a, b: int32): int32 =
    if a + b >= M:
        a + b - M
    else:
        a + b

proc `**`(a, b: int32): int32 =
    (a.int64 * b.int64 mod M.int64).int32

var a = 0'i32
var b = 1'i32

for i in 1..45:
    echo(b)
    let t = a ++ b
    a = b
    b = t
