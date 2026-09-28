namespace Esercizio3;
using Esercizio1;

public class TrackingEnumerable : IEnumerable<int>
{
    public int EnumerationCount {get;private set;} = 0;

    public IEnumerator<int> GetEnumerator()
    {
        EnumerationCount++;
        yield break;
    }

    IEnumerator IEnumerable.GetEnumerator() => GetEnumerator();
}


public class UnitTest1
{
    [Fact]
    public void Test1()
    {
        var tracker = new TrackingEnumerable();
        var result = tracker.TakeThenSkip(2, 3);
        
        Assert.Equal(0, tracker.EnumerationCount); // Non è stato ancora enumerato
    }

    [Fact]
    public void Test2()
    {
        var source = new TrackingEnumerable();
        var result = source.TakeThenSkip(2,3);
        result.ToList(); // forza enumerazione
        Assert.Equal(1, source.EnumerationCount);
    }

    [Fact]
    public void TakeThenSkip_WithInfiniteSequence_WorksCorrectly()
    {
        // Generatore di sequenza infinita
        IEnumerable<int> InfiniteSequence()
        {
            int i = 0;
            while (true) yield return i++;
        }

        var result = InfiniteSequence().TakeThenSkip(2, 3).Take(8).ToList();
        
        Assert.Equal(new[] { 0, 1, 5, 6, 10, 11, 15, 16 }, result);
    }
}
