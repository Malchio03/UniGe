namespace Esercizio2;
using Esercizio1;

public class UnitTest1
{
    [Fact]
    public void SanityCheck() 
    {
        IEnumerable<int[]> x = Array.Empty<int>().Windowed(3);
        _ = new List<string> { "a", "b" }.Windowed(1);
        _ = new[] { 3.14, 2.71, 1.41 }.Windowed(2);
    }

    [Fact]
    public void Empty_Array_Gives_Null()
    {
        var source = Array.Empty<int>();
        var result = source.Windowed(3);
        Assert.Empty(result);
    }

    [Fact]
    public void IntList_Size2_ReturnsCorrectWindows()
    {
        var source = new List<int>{1,2,3,4};
        var result = source.Windowed(2).ToList();

        Assert.Equal(3, result.Count);
        Assert.Equal(new[] {1,2}, result[0]);
        Assert.Equal(new[] {2,3}, result[1]);
        Assert.Equal(new[] {3,4}, result[2]);
    }

    [Fact]
    public void IntList_Size3_ReturnsSingleWindow()
    {
        var source = new List<int>{1,2,3};
        var result = source.Windowed(3).ToList();
        
        Assert.Single(result);
        Assert.Equal(new[] {1,2,3}, result[0]);
    }

    [Fact]
    public void IntArray_Size3_ReturnsNull()
    {
        var source = new [] {10,20};
        var result = source.Windowed(3).ToArray();

        Assert.Empty(result);
    }

    [Fact]
    public void StringArray_Size1_ReturnsCorrectWindows()
    {
        var source = new[] {"qui", "quo", "qua"};
        var result = source.Windowed(1).ToList();

        Assert.Equal(3, result.Count);
        Assert.Equal(new[] {"qui"}, result[0]);
        Assert.Equal(new[] {"quo"}, result[1]);
        Assert.Equal(new[] {"qua"}, result[2]);
    }

    // eccezioni
    [Fact]
    public void SizeZero_ThrowsImmediately()
    {
        var source = Array.Empty<int>();
        var invalidSize = 0;
        Assert.Throws<ArgumentOutOfRangeException>( () => source.Windowed(invalidSize));
    }

     [Fact]
    public void SizeNegative_ThrowsImmediately()
    {
        var source = Array.Empty<int>();
        var invalidSize = -7;
        Assert.Throws<ArgumentOutOfRangeException>( () => source.Windowed(invalidSize));
    }



}   
