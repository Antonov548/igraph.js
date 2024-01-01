describe('igraph.js', () => {
  it('shortest path', async () => {
    const igraph = global.igraph;

    const v = new igraph.vector_int([0, 1, 1, 2, 2, 3, 3, 4, 0, 3]);

    const g = igraph.create(v, 5, true);
    v.delete();

    igraph.get_shortest_path(g, 0, 4, igraph.neimode.OUT);

    // expect(vpath.data).toEqual(new Int32Array([0, 3, 4]));
    // expect(epath.data).toEqual(new Int32Array([4, 3]));

    g.delete();
  });
});
