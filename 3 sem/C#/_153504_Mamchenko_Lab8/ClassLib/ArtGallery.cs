namespace ClassLib
{
    public class ArtGallery
    {
        public int? Id { get; set; }
        
        public string? Name { get; set; }

        public int? NumberOfWorks { get; set; }

        public ArtGallery()
        {
            Id = null;
            Name = null;
            NumberOfWorks = null;
        }


        public ArtGallery(int? id, string? name, int? numberOfWorks)
        {
            Id = id;
            Name = name;
            NumberOfWorks = numberOfWorks;
        }        
    }
}