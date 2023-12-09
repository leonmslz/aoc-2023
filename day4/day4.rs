use std::fs;

fn matching_cards(mut y: Vec<Vec<Vec<&str>>>) -> Vec<u32> {
    let mut a: Vec<u32> = vec![]; 

    for i1 in 0..y.len()-1 {
        let mut c = 0;
        y[i1][0].remove(0);
        y[i1][0].remove(0);
        for i2 in 0..y[i1][0].len() {
            if y[i1][1].iter().any(|&i| i == y[i1][0][i2]) {
                c = c + 1;
            }
        }
        a.push(c);
    }

    return a;
}

fn solve1(filepath: &str) -> i32 {
    let i = fs::read_to_string(filepath).expect("");

    let y: Vec<Vec<Vec<&str>>> = i.split("\n")
                                  .map(|x: &str| x.split("|")
                                  .map(|x: &str| x.split_whitespace().collect()).collect()).collect();

    let mut p = 0;

    for c in matching_cards(y) {
        if c > 0 {
            p = p + i32::pow(2, c - 1);
        }
    }

    return p;
}

fn solve2(filepath: &str) -> i32 {
    let i = fs::read_to_string(filepath).expect("");

    let y: Vec<Vec<Vec<&str>>> = i.split("\n")
                                  .map(|x: &str| x.split("|")
                                  .map(|x: &str| x.split_whitespace().collect()).collect()).collect();

    let mut copies: Vec<i32> = vec![1; y.len()-1];
                                          
    for (i1, c) in matching_cards(y).iter().enumerate() {
        for x in 1..c+1 {
            copies[i1 + x as usize] = copies[i1 + x as usize] + copies[i1];
        }
    }

    let total: i32 = copies.iter().sum();

    return total;
}

fn main() {
    let filepath = "./input.txt";

    println!("{}", solve1(filepath));
    println!("{}", solve2(filepath));
}
