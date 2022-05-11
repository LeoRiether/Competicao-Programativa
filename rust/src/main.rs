#![allow(unused_imports)]
#![allow(unused_macros)]
// use proconio::input;
use std::cmp::{self, Ordering::*, Reverse};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, VecDeque};
use std::io::{self, BufWriter, Write};
use std::mem::swap;
use std::str::{self, SplitAsciiWhitespace};

// I have no idea what I'm doing

fn divisors(x: i32) -> BTreeSet<i32> {
    let mut r = BTreeSet::new();
    let mut d = 1;
    while d as i64 * d as i64 <= x as i64 {
        if x % d == 0 {
            r.insert(d);
            if x / d != d {
                r.insert(x / d);
            }
        }
        d += 1;
    }
    r
}

fn intersect(a: BTreeSet<i32>, b: BTreeSet<i32>) -> BTreeSet<i32> {
    a.intersection(&b).copied().collect()
}

fn union(a: BTreeSet<i32>, b: BTreeSet<i32>) -> BTreeSet<i32> {
    a.union(&b).copied().collect()
}

fn main() -> Result<(), io::Error> {
    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut scan = UnsafeScanner::new(stdin.lock());
    let mut out = BufWriter::new(stdout.lock());
 
    macro_rules! answer {
        ($ans:expr) => {
            writeln!(out, "{}", $ans)
        };
    }

    let t: i32 = scan.token();
    for _ in 0..t {
        let (w, l) = scan.pair::<i32>();

        let a = intersect(divisors(w), divisors(l-2));
        let b = intersect(divisors(w-2), divisors(l));
        let c = intersect(divisors(w-1), divisors(l-1));
        let ans = union(a, union(b, c));
        
        write!(out, "{} ", ans.len()).ok();
        for x in ans {
            write!(out, "{} ", x).ok();
        }
        writeln!(out).ok();
    }

    Ok(())
}

///////////////////////////////////////////////////////////////////////////////////////////////////

/// Mostly copied from https://github.com/EbTech/rust-algorithms/blob/master/src/scanner.rs
/// Same API as Scanner but nearly twice as fast, using horribly unsafe dark arts
/// **REQUIRES** Rust 1.34 or higher
pub struct UnsafeScanner<R> {
    reader: R,
    buf_str: Vec<u8>,
    buf_iter: SplitAsciiWhitespace<'static>,
}

impl<R: io::BufRead> UnsafeScanner<R> {
    pub fn new(reader: R) -> Self {
        Self {
            reader,
            buf_str: vec![],
            buf_iter: "".split_ascii_whitespace(),
        }
    }

    /// This function should be marked unsafe, but noone has time for that in a
    /// programming contest. Use at your own risk!
    pub fn token<T: str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buf_iter.next() {
                return token.parse().ok().expect("Failed parse [Scanner]");
            }
            self.buf_str.clear();
            self.reader
                .read_until(b'\n', &mut self.buf_str)
                .expect("Failed read");
            self.buf_iter = unsafe {
                let slice = str::from_utf8_unchecked(&self.buf_str);
                std::mem::transmute(slice.split_ascii_whitespace())
            }
        }
    }

    pub fn pair<T: str::FromStr>(&mut self) -> (T, T) {
        (self.token(), self.token())
    }

    pub fn vec<T: str::FromStr>(&mut self, n: usize) -> Vec<T> {
        (0..n).map(|_| self.token()).collect()
    }
}

// aka #![feature(bool_to_option)]
trait BoolThen {
    fn then_<T>(self, f: impl FnOnce() -> T) -> Option<T>;
}

impl BoolThen for bool {
    fn then_<T>(self, f: impl FnOnce() -> T) -> Option<T> {
        if self {
            Some(f())
        } else {
            None
        }
    }
}

trait BoolToYes {
    fn yes(self) -> &'static str;
}

impl BoolToYes for bool {
    fn yes(self) -> &'static str {
        match self {
            true => "YES",
            false => "NO",
        }
    }
}
