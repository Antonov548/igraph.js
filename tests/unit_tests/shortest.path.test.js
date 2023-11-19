describe('igraph.js', () => {
  it('shortest path', async () => {
    const igraph = global.igraph;

    const v = new igraph.vector_int([0, 1, 1, 2, 2, 3, 3, 4, 0, 3]);
    const g = new igraph.graph();

    igraph.create(g, v, 5, true);
    v.delete();

    const vpath = new igraph.vector_int();
    const epath = new igraph.vector_int();

    igraph.get_shortest_path(g, vpath, epath, 0, 4, igraph.neimode.OUT);

    expect(vpath.data).toEqual(new Int32Array([0, 3, 4]));
    expect(epath.data).toEqual(new Int32Array([4, 3]));

    igraph.destroy(g);
    g.delete();

    vpath.delete();
    epath.delete();
  });
});
