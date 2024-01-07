describe('igraph.js', () => {
  it('shortest path', async () => {
    const igraph = global.igraph;

    const v = new igraph.vector_int([0, 1, 1, 2, 2, 3, 3, 4, 0, 3]);

    const g = igraph.create(v, 5, true);
    v.delete();

    const r = igraph.get_shortest_path(g, 0, 4, igraph.neimode.OUT);

    expect(r.vertices.data).toEqual(new Int32Array([0, 3, 4]));
    expect(r.edges.data).toEqual(new Int32Array([4, 3]));

    g.delete();
  });

  it('shortest paths', async () => {
    const igraph = global.igraph;

    const v = new igraph.vector_int([0, 1, 0, 2, 1, 6, 2, 6, 1, 3, 1, 4, 1, 5,
      3, 2, 4, 2, 5, 2]);

    const g = igraph.create(v, 21, true);
    v.delete();

    g.delete();
  });
});
