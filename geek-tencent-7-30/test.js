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
for (let i = 0; i < 100; i++) {
    l.push(tttt.getBrickInfo(tttt.curRandomNum, tttt.brickCount + 1, [4, 0], true).brickRawInfo);
    tttt.curRandomNum = tttt.getRandomNum(tttt.curRandomNum);
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
    console.log(movestotake);
    if (movestotake != 0)
        moves.push((movestotake > 0 ? 'R' : 'L') + Math.abs(movestotake));
    moves.push('D' + (20 - tmpmove.landingHeight - 1));
}
moves.reduce((pv, v) => pv + "," + v, "").substr(1) + ",N";


let rsp = await(fetch("api/upload", {
    body: JSON.stringify({ record: s, score: 60392 }),
    method: "POST", headers: { 'Content-Type': 'application/json;charset=utf-8' }
}));

