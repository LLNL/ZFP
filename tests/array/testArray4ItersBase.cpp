TEST_F(ARRAY_DIMS_SCALAR_TEST_ITERS, given_partialBlocks_when_incrementIterator_then_positionTraversesCorrectly)
{
  // force partial block traversal
  EXPECT_NE(0u, arr.size_x() % BLOCK_SIDE_LEN);
  EXPECT_NE(0u, arr.size_y() % BLOCK_SIDE_LEN);
  EXPECT_NE(0u, arr.size_z() % BLOCK_SIDE_LEN);
  EXPECT_NE(0u, arr.size_w() % BLOCK_SIDE_LEN);

  uint totalBlocksX = (arr.size_x() + 3) / 4;
  uint totalBlocksY = (arr.size_y() + 3) / 4;
  uint totalBlocksZ = (arr.size_z() + 3) / 4;
  uint totalBlocksW = (arr.size_w() + 3) / 4;
  uint totalBlocks = totalBlocksX * totalBlocksY * totalBlocksZ * totalBlocksW;

  iter = arr.begin();
  for (uint count = 0; count < totalBlocks; count++) {
    // determine if block is complete or partial
    uint distanceFromEnd = arr.size_x() - iter.i();
    uint blockLenX = distanceFromEnd < BLOCK_SIDE_LEN ? distanceFromEnd : BLOCK_SIDE_LEN;

    distanceFromEnd = arr.size_y() - iter.j();
    uint blockLenY = distanceFromEnd < BLOCK_SIDE_LEN ? distanceFromEnd : BLOCK_SIDE_LEN;

    distanceFromEnd = arr.size_z() - iter.k();
    uint blockLenZ = distanceFromEnd < BLOCK_SIDE_LEN ? distanceFromEnd : BLOCK_SIDE_LEN;

    distanceFromEnd = arr.size_w() - iter.l();
    uint blockLenW = distanceFromEnd < BLOCK_SIDE_LEN ? distanceFromEnd : BLOCK_SIDE_LEN;

    // ensure entries lie in same block
    uint blockStartIndexI = iter.i();
    uint blockStartIndexJ = iter.j();
    uint blockStartIndexK = iter.k();
    uint blockStartIndexL = iter.l();

    for (uint l = 0; l < blockLenW; l++) {
      for (uint k = 0; k < blockLenZ; k++) {
        for (uint j = 0; j < blockLenY; j++) {
          for (uint i = 0; i < blockLenX; i++) {
            EXPECT_EQ(blockStartIndexI + i, iter.i());
            EXPECT_EQ(blockStartIndexJ + j, iter.j());
            EXPECT_EQ(blockStartIndexK + k, iter.k());
            EXPECT_EQ(blockStartIndexL + l, iter.l());
            iter++;
          }
        }
      }
    }
  }

//  EXPECT_EQ(arr.end(), iter); // triggers googletest issue #742
  EXPECT_TRUE(arr.end() == iter);
}

// const iterators

TEST_F(ARRAY_DIMS_SCALAR_TEST_ITERS, given_partialBlocks_when_incrementConstIterator_then_positionTraversesCorrectly)
{
  // force partial block traversal
  EXPECT_NE(0u, arr.size_x() % BLOCK_SIDE_LEN);
  EXPECT_NE(0u, arr.size_y() % BLOCK_SIDE_LEN);
  EXPECT_NE(0u, arr.size_z() % BLOCK_SIDE_LEN);
  EXPECT_NE(0u, arr.size_w() % BLOCK_SIDE_LEN);

  uint totalBlocksX = (arr.size_x() + 3) / 4;
  uint totalBlocksY = (arr.size_y() + 3) / 4;
  uint totalBlocksZ = (arr.size_z() + 3) / 4;
  uint totalBlocksW = (arr.size_w() + 3) / 4;
  uint totalBlocks = totalBlocksX * totalBlocksY * totalBlocksZ * totalBlocksW;

  citer = arr.cbegin();
  for (uint count = 0; count < totalBlocks; count++) {
    // determine if block is complete or partial
    uint distanceFromEnd = arr.size_x() - citer.i();
    uint blockLenX = distanceFromEnd < BLOCK_SIDE_LEN ? distanceFromEnd : BLOCK_SIDE_LEN;

    distanceFromEnd = arr.size_y() - citer.j();
    uint blockLenY = distanceFromEnd < BLOCK_SIDE_LEN ? distanceFromEnd : BLOCK_SIDE_LEN;

    distanceFromEnd = arr.size_z() - citer.k();
    uint blockLenZ = distanceFromEnd < BLOCK_SIDE_LEN ? distanceFromEnd : BLOCK_SIDE_LEN;

    distanceFromEnd = arr.size_w() - citer.l();
    uint blockLenW = distanceFromEnd < BLOCK_SIDE_LEN ? distanceFromEnd : BLOCK_SIDE_LEN;

    // ensure entries lie in same block
    uint blockStartIndexI = citer.i();
    uint blockStartIndexJ = citer.j();
    uint blockStartIndexK = citer.k();
    uint blockStartIndexL = citer.l();

    for (uint l = 0; l < blockLenW; l++) {
      for (uint k = 0; k < blockLenZ; k++) {
        for (uint j = 0; j < blockLenY; j++) {
          for (uint i = 0; i < blockLenX; i++) {
            EXPECT_EQ(blockStartIndexI + i, citer.i());
            EXPECT_EQ(blockStartIndexJ + j, citer.j());
            EXPECT_EQ(blockStartIndexK + k, citer.k());
            EXPECT_EQ(blockStartIndexL + l, citer.l());
            citer++;
          }
        }
      }
    }
  }

//  EXPECT_EQ(arr.cend(), citer); // triggers googletest issue #742
  EXPECT_TRUE(arr.cend() == citer);
}
