namespace Esercizio3;
using Esercizio1;

public class UnitTest1
{
    [Fact]
    public void Test1()
    {
        int numeroEnumerazioni = 0; // contatore

        // sequenza dei dati
        IEnumerable<int> source()
        {
            numeroEnumerazioni++;
            yield return 10;
            yield return 20;
            yield return 30;
        }

        var windows = source().Windowed(2);
        Assert.Equal(0, numeroEnumerazioni); // lazy evaluation

        var listaRisultati = windows.ToList();
        Assert.Equal(1, numeroEnumerazioni);
    }

    [Fact]
    public void SequenzaInfinita()
    {
        // creo la sequenza infinita di interi
        IEnumerable<int> SequenzaInfinita()
        {
            int i = 0;
            while (true)
            {
                yield return i++;
            }
        }

        var risultati = SequenzaInfinita().Windowed(3).Take(4).ToList();

        Assert.Equal(4, risultati.Count);
        Assert.Equal(new[] { 0, 1, 2 }, risultati[0]);
        Assert.Equal(new[] { 1, 2, 3 }, risultati[1]);
        Assert.Equal(new[] { 2, 3, 4 }, risultati[2]);
        Assert.Equal(new[] { 3, 4, 5 }, risultati[3]);
    }


    // ALTRO METODO VALIDO UGUALE E PIÙ SEMPLICE








    
//     public class Sequenza : IEnumerable<int>
// {
//     public int count {get; private set;} = 0;
//     public IEnumerator<int> GetEnumerator()
//     {
//         count++;
//         yield break;
//     }
//     IEnumerator IEnumerable.GetEnumerator() => GetEnumerator();
// }
// public class UnitTest1
// {
//     [Fact]
//     public void Test1()
//     {
//         var source = new Sequenza();
//         var result = source.Windowed(2);
//         Assert.Equal(0, source.count);
//         result.ToList();
//         Assert.Equal(1, source.count);

//         IEnumerable<int> Infinito()
//         {
//             int i = 0;
//             while (true)
//             {
//                 yield return i++;
//             }
//         }

//         var ris = Infinito().Windowed(3).Take(4).ToList();
//         Assert.Equal([0,1,2], ris[0]);
//         Assert.Equal([1,2,3], ris[1]);
//         Assert.Equal([2,3,4], ris[2]);
//         Assert.Equal([3,4,5], ris[3]);
//     }
// }

}
