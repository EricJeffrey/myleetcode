let a = [1, 2, 3, 4, 4, 4, 3, 2, 0, 2, 1];
let b = [2, 3, 1, 1, 13, 4, 0, 23];
function print(s) {
    console.log(s);
}

let a = readline().split(',');
let b = readline().split(',');
print(a.concat(b).sort((u, v) => u - v).filter((v, i, a) => {
    return i == 0 ? true : v != a[i - 1];
}).join(','));
