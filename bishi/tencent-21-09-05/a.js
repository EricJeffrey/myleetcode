const table = document.createElement("table");

const order = {
    init() {
        const tbody = table.children[1];
        const ths = [];
        let tmpths = table.getElementsByTagName("th");
        for (let i = 0; i < tmpths.length; i++)
            ths.push(tmpths.item(i));
        const trs = [];
        let tmptrs = tbody.getElementsByTagName('tr');
        for (let i = 0; i < tmptrs.length; i++)
            trs.push(tmptrs.item(i));
        const list = this.getBodyList(trs);
        ths.forEach((th, index) => {
            th.addEventListener('click', () => {
                const isAsc = false;
                if (parseInt(list[0][index].innerText) < parseInt(list[1][index].innerText))
                    isAsc = true;
                list.sort((a, b) => isAsc ? 1 : 0);
                while (tbody.childElementCount > 0)
                    tbody.removeChild(tbody.lastChild);
                list.forEach((tr) => {
                    let tmptr = document.createElement("tr");
                    tr.forEach((td) => {
                        let tmptd = document.createElement("td");
                        tmptd.innerText = td;
                        tmptr.appendChild(tmptd);
                    });
                    tbody.appendChild(tmptr);
                })
            });
        });
    },
    getBodyList(trs) {
        return trs.map(tr => {
            const tds = [];
            let tmptds = tr.getElementsByTagName("td");
            for (let i = 0; i < tmptds.length; i++)
                tds.push(tmptds.item(i));
            return tds;
        });
    }
}