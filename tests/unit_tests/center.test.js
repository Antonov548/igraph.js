describe('igraph.js', () => {
  it('empty center', async () => {
    const igraph = global.igraph;

    const g = igraph.empty(0, false);

    const center = igraph.graph_center(g, igraph.neimode.OUT);
    expect(center.data).toEqual(new Int32Array([]));

    center.delete();
    g.delete();
  });

  it('undirected path graph center', async () => {
    const igraph = global.igraph;

    const g = igraph.ring(5, false, 0, 0);

    const center = igraph.graph_center(g, igraph.neimode.OUT);
    expect(center.data).toEqual(new Int32Array([2]));

    center.delete();
    g.delete();
  });

  it('undirected graph center', async () => {
    const igraph = global.igraph;

    const v = new igraph.vector_int([0, 1, 1, 2, 0, 2, 3, 0, 4, 1, 2, 5]);

    const g = igraph.create(v, 6, false);
    v.delete();

    const center = igraph.graph_center(g, igraph.neimode.OUT);
    expect(center.data).toEqual(new Int32Array([0, 1, 2]));

    center.delete();
    g.delete();
  });

  it('in-star graph center', async () => {
    const igraph = global.igraph;

    const g = igraph.star(10, igraph.starmode.OUT, 0);

    const center = igraph.graph_center(g, igraph.neimode.OUT);
    expect(center.data).toEqual(new Int32Array([1, 2, 3, 4, 5, 6, 7, 8, 9]));

    center.delete();
    g.delete();
  });
});
