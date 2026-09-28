using Esercizio1;

namespace Eserfcizio3;

public class UnitTest1
{
    [Theory]
    [InlineData(100,5)]
    [InlineData(50,7)]
    [InlineData(1234,11)]
    public void EveryNInfiniteTest(int howMany, int n)
    {
        // creo sequenza infinita
        IEnumerable<int> sequenza()
        {
            int i = 0;
            while (true)
            {
                yield return i++;
            }
        }

        var firstHMR = sequenza().EveryN(n).Take(howMany).ToList();
        for (int i = 0; i < howMany; i++)
        {
            Assert.Equal(i * n, firstHMR[i]);
        }
    }
}
