describe('igraph.js', () => {
  it('edges', async () => {
    const igraph = global.igraph;

    const g = igraph.empty(10, true);

    const edges = [0, 1, 1, 2, 2, 3, 2, 2];
    const v = new igraph.vector_int(edges);

    igraph.add_edges(g, v, 0);

    v.delete();

    const ec = igraph.ecount(g);
    const ec2 = edges.length / 2;
    expect(ec).toEqual(ec2);

    const v1 = new igraph.vector_int([0, 1, 2]);
    expect(() => { igraph.add_edges(g, v1, 0) }).toThrow();

    v1.delete();
    g.delete();
  });
});
