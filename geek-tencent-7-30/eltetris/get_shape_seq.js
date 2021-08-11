

function nextShape() {
    if (window.randomConfig == undefined) {
        window.randomConfig = {
            a: 27073, // 乘子
            M: 32749, // 模数
            v: 12358, // 随机数种子
            C: 17713, // 增量
        };
    }
    function getShape(randomNum, brickCount) {
        const weightIndex = randomNum % 29; // 对形状的概率有一定要求：限制每种砖块的出现概率可以让游戏变得更有挑战性
        const stateIndex = brickCount % 4; // 形态概率要求不高，随机即可
        let shapeIndex = 0;

        // const testShapeIndex = Math.floor(brickCount / 4);
        // const testStateIndex = brickCount % shapes[0].length;

        // I,L,J,T,O,S,Z 型方块的概率权重分别为：2,3,3,4,5,6,6（和为29）
        if (weightIndex >= 0 && weightIndex <= 1) {
            shapeIndex = 0;
        } else if (weightIndex > 1 && weightIndex <= 4) {
            shapeIndex = 1;
        } else if (weightIndex > 4 && weightIndex <= 7) {
            shapeIndex = 2;
        } else if (weightIndex > 7 && weightIndex <= 11) {
            shapeIndex = 3;
        } else if (weightIndex > 11 && weightIndex <= 16) {
            shapeIndex = 4;
        } else if (weightIndex > 16 && weightIndex <= 22) {
            shapeIndex = 5;
        } else if (weightIndex > 22) {
            shapeIndex = 6;
        }
        return { shapeIndex, stateIndex };
    }

    function getRandomNum(v) {
        return (v * window.randomConfig.a + window.randomConfig.C) % window.randomConfig.M;
    }
    if (window.randomConfig == undefined) {
    }
    if (window.tttt == undefined) {
        window.tttt = { curRandom: window.randomConfig.v, brickCount: 0 };
    }
    if (window.ttttShapeSeq == undefined) {
        window.ttttShapeSeq = ['I', 'L', 'J', 'T', 'O', 'S', 'Z'];
    }
    window.tttt.curRandom = getRandomNum(window.tttt.curRandom);
    let nextShape = getShape(window.tttt.curRandom, window.tttt.brickCount);
    nextShape.shape = window.ttttShapeSeq[nextShape.shapeIndex];
    window.tttt.brickCount += 1;
    return nextShape;
}