const randomConfig = {
    a: 27073, // 乘子
    M: 32749, // 模数
    C: 17713, // 增量
    v: 12358, // 随机数种子
}
const defaultBrickCenterPos = [4, 0];

const config = {
    // 格子宽高及单位配置
    gridConfig: {
        width: 200,
        height: 400,
        row: 20,
        col: 10,
    },

    // 方块的颜色，可设置为不同颜色，当前设置为统一色
    colors: ['#00b050', '#00b050', '#00b050', '#00b050'],

    // 7 种类型方块（I,L,J,T,O,S,Z）的形态及每种类型对应的 4 个形态
    // 注：游戏使用的坐标系为 canvas 坐标系（坐标原点在左上角）详见：https://developer.mozilla.org/zh-CN/docs/Web/API/Canvas_API/Tutorial/Drawing_shapes
    shapes: [
        [
            // I 型
            [
                [0, 0],
                [0, -1],
                [0, -2],
                [0, 1],
            ],
            [
                [0, 0],
                [1, 0],
                [2, 0],
                [-1, 0],
            ],
            [
                [0, 0],
                [0, -1],
                [0, -2],
                [0, 1],
            ],
            [
                [0, 0],
                [1, 0],
                [2, 0],
                [-1, 0],
            ],
        ],
        [
            // L 型
            [
                [0, 0],
                [0, -1],
                [0, -2],
                [1, 0],
            ],
            [
                [0, 0],
                [1, 0],
                [2, 0],
                [0, 1],
            ],
            [
                [0, 0],
                [-1, 0],
                [0, 1],
                [0, 2],
            ],
            [
                [0, 0],
                [0, -1],
                [-1, 0],
                [-2, 0],
            ],
        ],
        [
            // J 型
            [
                [0, 0],
                [0, -1],
                [0, -2],
                [-1, 0],
            ],
            [
                [0, 0],
                [0, -1],
                [1, 0],
                [2, 0],
            ],
            [
                [0, 0],
                [1, 0],
                [0, 1],
                [0, 2],
            ],
            [
                [0, 0],
                [-1, 0],
                [-2, 0],
                [0, 1],
            ],
        ],
        [
            // T 型
            [
                [0, 0],
                [1, 0],
                [0, 1],
                [-1, 0],
            ],
            [
                [0, 0],
                [0, -1],
                [0, 1],
                [-1, 0],
            ],
            [
                [0, 0],
                [0, -1],
                [1, 0],
                [-1, 0],
            ],
            [
                [0, 0],
                [0, -1],
                [1, 0],
                [0, 1],
            ],
        ],
        [
            // O 型
            [
                [0, 0],
                [0, -1],
                [1, -1],
                [1, 0],
            ],
            [
                [0, 0],
                [0, -1],
                [1, -1],
                [1, 0],
            ],
            [
                [0, 0],
                [0, -1],
                [1, -1],
                [1, 0],
            ],
            [
                [0, 0],
                [0, -1],
                [1, -1],
                [1, 0],
            ],
        ],
        [
            // S 型
            [
                [0, 0],
                [0, -1],
                [1, -1],
                [-1, 0],
            ],
            [
                [0, 0],
                [-1, 0],
                [-1, -1],
                [0, 1],
            ],
            [
                [0, 0],
                [0, -1],
                [1, -1],
                [-1, 0],
            ],
            [
                [0, 0],
                [-1, 0],
                [-1, -1],
                [0, 1],
            ],
        ],
        [
            // Z 型
            [
                [0, 0],
                [0, -1],
                [1, 0],
                [-1, -1],
            ],
            [
                [0, 0],
                [0, -1],
                [-1, 1],
                [-1, 0],
            ],
            [
                [0, 0],
                [0, -1],
                [1, 0],
                [-1, -1],
            ],
            [
                [0, 0],
                [0, -1],
                [-1, 1],
                [-1, 0],
            ],
        ],
    ],

    // 操作动作到提交类型的映射
    actionMap: {
        down: 'D', // 下降
        left: 'L', // 左移
        right: 'R', // 右移
        rotate: 'C', // 旋转
        new: 'N', // 新方块
    },

    // 操作动作到提交类型的反向映射
    actionMapReversed: {
        D: 'down',
        L: 'left',
        R: 'right',
        C: 'rotate',
        N: 'new',
    },
};



// --------------------

let tttt = new Tetris();
tttt.curRandomNum = tttt.getRandomNum(tttt.curRandomNum);
let l = []
for (let i = 0; i < 10000; i++) {
    l.push(tttt.getBrickInfo(tttt.curRandomNum, tttt.brickCount, [4, 0], true).brickRawInfo);
    tttt.curRandomNum = tttt.getRandomNum(tttt.curRandomNum);
    tttt.brickCount += 1;
}

var moves = []
for (let i = 0; i < Math.min(window.tttt_moves.length, 1000000); i++) {
    moves.push('N');
    let tmppiece = window.tttt_pieces[i];
    let tmpmove = window.tttt_moves[i];
    let tmp_ori_index = parseInt(tmpmove.orientation_index);
    let which = tmppiece.which;
    let tmpcnt = 0;
    for (let j = tmppiece.state_index; j % (config.shapes[which].length) != tmp_ori_index; j++) {
        tmpcnt += 1;
    }
    if (tmpcnt > 0)
        moves.push('C' + tmpcnt);
    let newpos = tmppiece.pos;
    for (let j = 1; j < 4; j++) {
        newpos[j][0] = 4 + config.shapes[which][tmp_ori_index][j][0];
        newpos[j][1] = config.shapes[which][tmp_ori_index][j][1];
    }
    // let has = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
    // // 方块高度
    // for (let j = 1; j < 4; j++) {
    //     has[newpos[j][1] + 4] = 1;
    // }
    // let height = has.reduce((pv, v) => pv + v, 0);

    // 最左边的col在哪
    let mincol = newpos[0][0];
    for (let j = 1; j < 4; j++) {
        mincol = Math.min(newpos[j][0], mincol);
    }
    // mincol -= 1;
    let movestotake = tmpmove.column - mincol;
    if (movestotake != 0)
        moves.push((movestotake > 0 ? 'R' : 'L') + Math.abs(movestotake));
    if (tmpmove.landingHeight == 19) break;
    moves.push('D' + (20 - tmpmove.landingHeight - 1));
}
let s = moves.reduce((pv, v) => pv + "," + v, "").substr(1) + ",N";
let ncnt = 0;
for (let i = 0; i < s.length; i++) {
    if (s[i] == 'N') {
        ncnt++;
    }
    if (ncnt == 10000) {
        s = s.substr(0, i - 1);
        break;
    }
}
console.log(s);
console.log(window.tttt_scores.reduce((pv, v) => pv + v, 0));



let doit = function (score = 0) {
    axios.post(`api/upload`, { record: s, score: score })
        .then(({ data }) => {
            console.log('提交结果', data);
            if (data.info) { console.log(data.info) }
        });
}

/*
随机测试
function shuffle(array) {
    var currentIndex = array.length, randomIndex;
    // While there remain elements to shuffle...
    while (0 !== currentIndex) {
        // Pick a remaining element...
        randomIndex = Math.floor(Math.random() * currentIndex);
        currentIndex--;
        // And swap it with the current element.
        [array[currentIndex], array[randomIndex]] = [array[randomIndex], array[currentIndex]];
    }
    return array;
}
let nums7 = [], nums8 = [], nums9 = [];
for (let i = 0.8; i <= 1.5; i += 0.01) nums7.push(i);
for (let i = 90; i <= 160; i++) nums8.push(i);
for (let i = 2; i <= 8; i += 0.1) nums9.push(i);
let nums = [];
for (let i = 0; i < nums7.length; i++) {
    for (let j = 0; j < nums8.length; j++) {
        for (let k = 0; k < nums9.length; k++) {
            nums.push({ i: nums7[i], j: nums8[j], k: nums9[k] });
        }
    }
}
nums = shuffle(nums);

for (let i = 0; i < nums.length; i++) {
    window.nums[7] = nums[i].i;
    window.nums[8] = nums[i].j;
    window.nums[9] = nums[i].k;
    $("#play").click();
    $("#play").click();
}

*/